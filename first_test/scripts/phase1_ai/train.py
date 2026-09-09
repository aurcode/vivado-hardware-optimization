#!/usr/bin/env python3
"""
Phase 1: Training Script for Hardware-Compliant Track A MLP on MNIST
Features:
- Strict zero-bias constraint verification
- Standardized normalization to [0.0, 1.0] for hardware fixed-point alignment
- Training with Adam optimizer and validation against the >= 90% benchmark
- Saves model checkpoint for Post-Training Quantization (PTQ)
"""

import os
import argparse
import torch
import torch.nn as nn
import torch.optim as optim
from torch.utils.data import DataLoader
from torchvision import datasets, transforms
from models import HardwareMLP

def get_dataloaders(batch_size=64, data_dir="./data"):
    transform = transforms.Compose([
        transforms.ToTensor(), # Scales [0, 255] -> [0.0, 1.0]
    ])
    
    os.makedirs(data_dir, exist_ok=True)
    train_dataset = datasets.MNIST(root=data_dir, train=True, download=True, transform=transform)
    test_dataset = datasets.MNIST(root=data_dir, train=False, download=True, transform=transform)
    
    train_loader = DataLoader(train_dataset, batch_size=batch_size, shuffle=True)
    test_loader = DataLoader(test_dataset, batch_size=batch_size, shuffle=False)
    
    return train_loader, test_loader

def evaluate(model, test_loader, device):
    model.eval()
    correct = 0
    total = 0
    with torch.no_grad():
        for data, targets in test_loader:
            data, targets = data.to(device), targets.to(device)
            outputs = model(data)
            preds = outputs.argmax(dim=1)
            correct += (preds == targets).sum().item()
            total += targets.size(0)
    acc = 100.0 * correct / total
    return acc

def train(epochs=8, batch_size=64, lr=1e-3, checkpoint_path="checkpoint_mlp.pt"):
    device = torch.device("cpu")
    print(f"[*] Initializing Training on device: {device}")
    
    train_loader, test_loader = get_dataloaders(batch_size=batch_size)
    model = HardwareMLP().to(device)
    
    # Verify zero-bias rule
    for name, param in model.named_parameters():
        if "bias" in name:
            raise ValueError(f"Constraint Violation: Found bias parameter {name}")
    print("[*] Verified hardware constraint: 100% Bias-free network confirmed.")

    criterion = nn.CrossEntropyLoss()
    optimizer = optim.Adam(model.parameters(), lr=lr, weight_decay=1e-4)

    best_acc = 0.0
    print(f"[*] Training HardwareMLP (784 -> 128 -> 64 -> 10) for {epochs} epochs...")
    for epoch in range(1, epochs + 1):
        model.train()
        running_loss = 0.0
        for data, targets in train_loader:
            data, targets = data.to(device), targets.to(device)
            optimizer.zero_grad()
            outputs = model(data)
            loss = criterion(outputs, targets)
            loss.backward()
            optimizer.step()
            running_loss += loss.item() * data.size(0)

        epoch_loss = running_loss / len(train_loader.dataset)
        test_acc = evaluate(model, test_loader, device)
        print(f"    Epoch {epoch:02d}/{epochs:02d} | Train Loss: {epoch_loss:.4f} | Test Accuracy: {test_acc:.2f}%")

        if test_acc > best_acc:
            best_acc = test_acc
            torch.save(model.state_dict(), checkpoint_path)

    print(f"\n[+] Training Complete! Best Test Accuracy: {best_acc:.2f}%")
    print(f"[+] Saved optimal checkpoint to: {checkpoint_path}")
    
    if best_acc >= 90.0:
        print("[+] LEVEL 1 REQUIREMENT MET (>= 90% accuracy).")
    else:
        print("[!] WARNING: Test accuracy fell below 90% threshold.")

    return best_acc

if __name__ == "__main__":
    parser = argparse.ArgumentParser(description="Train Hardware-Compliant MLP on MNIST")
    parser.add_argument("--epochs", type=int, default=8, help="Number of training epochs")
    parser.add_argument("--batch-size", type=int, default=64, help="Batch size")
    parser.add_argument("--lr", type=float, default=1e-3, help="Learning rate")
    parser.add_argument("--checkpoint", type=str, default="checkpoint_mlp.pt", help="Checkpoint output path")
    args = parser.parse_args()

    train(epochs=args.epochs, batch_size=args.batch_size, lr=args.lr, checkpoint_path=args.checkpoint)
