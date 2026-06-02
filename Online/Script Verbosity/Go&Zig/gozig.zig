const std = @import("std");
const Message = @import("cache_message.zig");

export fn bridge_allocate(count: usize) [*]Message.MessageCache {
    const allocator = std.heap.page_allocator;
    const slice = allocator.alloc(Message.MessageCache, count) catch return @ptrFromInt(0);
    return slice.ptr;
}
