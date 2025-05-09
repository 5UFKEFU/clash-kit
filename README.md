# ClashKit

ClashKit 是一个用于 iOS 和 Android 平台的 Clash 核心库，基于 [mihomo](https://github.com/MetaCubeX/mihomo) 项目开发。

## 环境要求

- Go 1.23 或更高版本
- Xcode（用于 iOS 构建）
- Android SDK（用于 Android 构建）
- gomobile 工具链

## 安装步骤

### 1. 安装 Go

```bash
# 安装 Go 1.23.9
go install golang.org/dl/go1.23.9@latest
go1.23.9 download
```

### 2. 安装构建工具

```bash
# 安装 gomobile 和 gobind
go1.23.9 install golang.org/x/mobile/cmd/gomobile@latest
go1.23.9 install golang.org/x/mobile/cmd/gobind@latest

# 安装必要的绑定包
go1.23.9 get golang.org/x/mobile/bind
go1.23.9 get golang.org/x/mobile/bind/objc

# 初始化 gomobile
gomobile init
```

## 构建说明

### 构建 iOS 和 Android 库

```bash
make build
```

构建完成后，生成的文件将位于：
- iOS: `target/ios/`
- Android: `target/android/`

### 构建标签说明

项目使用以下构建标签来优化不同平台的构建：

- `no_cgo`：禁用 CGO
- `ios/ios_simulator/android`：平台特定代码
- `no_libproc`：避免 libproc.h 依赖
- `ios_cpu`：使用自定义 CPU 信息实现

## iOS 应用集成

### 1. 添加文件到项目

将 `target/ios` 目录下的以下文件添加到您的 Xcode 项目中：
- `ClashKit.objc.h`
- `ClashKit.objc.m`
- `ClashKit.a`

### 2. 配置项目设置

1. 在 Xcode 项目设置中：
   - 将 `ClashKit.a` 添加到 "Link Binary With Libraries"
   - 在 "Build Settings" 中设置 "Enable Bitcode" 为 No
   - 在 "Build Settings" 中设置 "Valid Architectures" 包含 arm64 和 x86_64

2. 在项目的 Bridging Header 中添加：
```objc
#import "ClashKit.objc.h"
```

### 3. 使用示例

```swift
import Foundation

class ClashManager {
    private let clash: ClashKitClash
    
    init() {
        clash = ClashKitClash()
    }
    
    func setup(homeDir: String, config: String) {
        // 设置 Clash
        clash.setup(withHomeDir: homeDir, config: config)
    }
    
    func getConfigGeneral() -> [String: Any]? {
        // 获取配置
        if let data = clash.getConfigGeneral() {
            return try? JSONSerialization.jsonObject(with: data) as? [String: Any]
        }
        return nil
    }
    
    func patchSelector(mapping: [String: String]) -> Bool {
        // 更新选择器
        if let data = try? JSONSerialization.data(withJSONObject: mapping) {
            return clash.patchSelector(with: data)
        }
        return false
    }
}

// 使用示例
let manager = ClashManager()
manager.setup(homeDir: "/path/to/home", config: "your_config_content")
```

### 4. 注意事项

1. 确保在 Info.plist 中添加必要的权限：
```xml
<key>NSAppTransportSecurity</key>
<dict>
    <key>NSAllowsArbitraryLoads</key>
    <true/>
</dict>
```

2. 如果需要使用网络扩展功能，需要：
   - 添加 Network Extension 能力
   - 在 Capabilities 中启用 Network Extensions
   - 配置相应的 App Groups

3. 内存管理：
   - ClashKit 对象会在 Swift 中自动管理内存
   - 不需要手动调用 release 或 dealloc

## 项目结构

```
.
├── clash/           # 核心代码
│   ├── clash.go     # 主要实现
│   └── cpu_override.go  # CPU 信息替代实现
├── target/          # 构建输出目录
│   ├── ios/         # iOS 平台文件
│   └── android/     # Android 平台文件
├── Makefile         # 构建脚本
└── go.mod           # Go 模块定义
```

## 依赖说明

主要依赖：
- github.com/metacubex/mihomo v1.18.0
- golang.org/x/mobile v0.0.0-20250506005352-78cd7a343bde

特殊依赖处理：
```go
replace github.com/shirou/gopsutil/v3 => github.com/shirou/gopsutil/v3 v3.21.12
```

## 常见问题

### 1. libproc.h 相关错误

如果遇到 `libproc.h` 相关错误，请确保：
- 已正确安装 Xcode 命令行工具
- 使用 `no_libproc` 构建标签
- 使用自定义的 CPU 信息实现

### 2. gomobile 初始化失败

如果 gomobile 初始化失败，请尝试：
```bash
go clean -modcache
go install golang.org/x/mobile/cmd/gomobile@latest
gomobile init
```

### 3. iOS 集成问题

如果遇到链接错误，请检查：
- 是否正确添加了所有必要的文件
- 是否正确配置了项目设置
- 是否添加了必要的权限声明

## 许可证

本项目基于 [mihomo](https://github.com/MetaCubeX/mihomo) 项目开发，遵循相同的许可证。