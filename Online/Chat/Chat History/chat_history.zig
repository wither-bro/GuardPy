const std = @import("std");
const Message = @import("../../Messages/Message/cache_message.zig");

pub const ChatHistory = struct {
    buffer: [*]Message.MessageCache,
    capacity: usize,
    count: usize,
    head: usize,

    pub fn init(allocator: std.mem.Allocator, capacity: usize) !*ChatHistory {
        const history = try allocator.create(ChatHistory);
        const buf = try allocator.alloc(Message.MessageCache, capacity);
        
        history.* = ChatHistory{
            .buffer = buf.ptr,
            .capacity = capacity,
            .count = 0,
            .head = 0,
        };
        return history;
    }

    pub fn add(self: *ChatHistory, msg: Message.MessageCache) void {
        self.buffer[self.head] = msg;
        
        if (self.count < self.capacity) {
            self.count += 1;
        }
        
        self.head = (self.head + 1) % self.capacity;
    }
};

export fn create_history(capacity: usize) *ChatHistory {
    const allocator = std.heap.page_allocator;
    return ChatHistory.init(allocator, capacity) catch @ptrFromInt(0);
}

export fn add_to_history(history: *ChatHistory, msg: Message.MessageCache) void {
    history.add(msg);
}
