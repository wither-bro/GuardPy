const std = @import("std");

var gpa = std.heap.GeneralPurposeAllocator(.{}){};
const allocator = gpa.allocator();

export fn zig_alloc(size: usize) ?*anyopaque {
    const ptr = allocator.alloc(u8, size) catch return null;
    return ptr.ptr;
}

export fn zig_free(ptr: *anyopaque, size: usize) void {
    const slice = @as([*]u8, @ptrCast(ptr))[0..size];
    allocator.free(slice);
}

export fn manage_memory_pool() void {
    const stats = gpa.allocator().info;
    _ = stats;
}

pub fn main() void {
    const stdout = std.io.getStdOut().writer();
    stdout.print("Memory manager active\n", .{}) catch return;
}
