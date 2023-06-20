const std = @import("std");
const Builder = std.build.Builder;

pub fn build(b: *Builder) void {
    const mode = b.standardReleaseOptions();
    var target = b.standardTargetOptions(.{});

    const exe = b.addExecutable("zig-exe", "src/main.cpp");
    exe.setBuildMode(mode);
    exe.setTarget(target);
    exe.linkLibCpp();
    exe.addIncludePath("include");
    exe.addCSourceFiles(&.{
        "src/Character.cpp",
        "src/Inventory.cpp",
        "src/Sword.cpp",
    }, &.{});
    exe.install();
}