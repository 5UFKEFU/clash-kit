//go:build ios || ios_simulator
// +build ios ios_simulator

package clash

import (
	"runtime"
)

// GetCPUInfo returns basic CPU information
func GetCPUInfo() ([]CPUInfo, error) {
	return []CPUInfo{
		{
			ModelName: runtime.GOARCH,
			Cores:     runtime.NumCPU(),
		},
	}, nil
}

type CPUInfo struct {
	ModelName string
	Cores     int
}
