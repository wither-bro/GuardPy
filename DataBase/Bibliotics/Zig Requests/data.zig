const std = @import("std");

pub const DataPacket = struct {
    allocator: std.mem.Allocator,
    payload: []const u8,
    timestamp: i64,

    pub fn init(allocator: std.mem.Allocator, payload: []const u8) !DataPacket {
        const copy = try allocator.alloc(u8, payload.len);
        @memcpy(copy, payload);
        return .{
            .allocator = allocator,
            .payload = copy,
            .timestamp = std.time.timestamp(),
        };
    }

    pub fn deinit(self: *DataPacket) void {
        self.allocator.free(self.payload);
    }
};
