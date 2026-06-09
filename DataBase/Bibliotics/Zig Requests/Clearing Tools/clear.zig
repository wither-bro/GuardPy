// Data Base/Bibliotics/Zig Requests/Clearing Tools/clear.zig
const std = @import("std");

pub const ClearTool = struct {
    name: []const u8,
    target_path: []const u8,
    is_active: bool,

    pub fn init(name: []const u8, path: []const u8) ClearTool {
        return .{
            .name = name,
            .target_path = path,
            .is_active = true,
        };
    }

    pub fn perform(self: *ClearTool) void {
        if (self.is_active) {
            std.debug.print("CLEANING_TOOL: {s} at {s} started.\n", .{ self.name, self.target_path });
        }
    }
};
