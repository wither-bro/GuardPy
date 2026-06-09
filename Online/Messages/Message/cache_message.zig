const std = @import("std");

pub const MessageCache = struct {
    id: [32]u8,
    sender: [32]u8,
    content: [960]u8,
    timestamp: i64,
    padding: [12]u8,

    pub fn init(id: []const u8, sender: []const u8, content: []const u8) MessageCache {
        var msg = MessageCache{
            .id = [_]u8{0} ** 32,
            .sender = [_]u8{0} ** 32,
            .content = [_]u8{0} ** 960,
            .timestamp = std.time.timestamp(),
            .padding = [_]u8{0} ** 12,
        };

        @memcpy(msg.id[0..@min(id.len, 32)], id);
        @memcpy(msg.sender[0..@min(sender.len, 32)], sender);
        @memcpy(msg.content[0..@min(content.len, 960)], content);

        return msg;
    }
}; 

export fn allocate_message_buffer(count: usize) [*]MessageCache {
    const allocator = std.heap.page_allocator;
    const slice = allocator.alloc(MessageCache, count) catch return @ptrFromInt(0);
    return slice.ptr;
}
