// Data Base/Bibliotics/Zig Requests/Clearing Tools/clear_system.zig
const std = @import("std");
const ClearTool = @import("clear.zig").ClearTool;

pub const ClearSystem = struct {
    tools: std.ArrayList(ClearTool),
    allocator: std.mem.Allocator,

    pub fn init(allocator: std.mem.Allocator) ClearSystem {
        return .{
            .tools = std.ArrayList(ClearTool).init(allocator),
            .allocator = allocator,
        };
    }

    pub fn registerTool(self: *ClearSystem, tool: ClearTool) !void {
        try self.tools.append(tool);
    }

    pub fn runAll(self: *ClearSystem) void {
        for (self.tools.items) |*tool| {
            tool.perform();
        }
    }

    pub fn deinit(self: *ClearSystem) void {
        self.tools.deinit();
    }
};
