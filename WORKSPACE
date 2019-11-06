# Copy from bazel-helloworld

workspace(name = "cpp_demo")

load("@bazel_tools//tools/build_defs/repo:http.bzl", "http_archive")
load("@bazel_tools//tools/build_defs/repo:git.bzl", "new_git_repository", "git_repository")

# abseil-cpp
http_archive(
  name = "com_google_absl",
  urls = ["https://github.com/abseil/abseil-cpp/archive/7c7754fb3ed9ffb57d35fe8658f3ba4d73a31e72.zip"],  # 2019-03-14
  strip_prefix = "abseil-cpp-7c7754fb3ed9ffb57d35fe8658f3ba4d73a31e72",
  sha256 = "71d00d15fe6370220b6685552fb66e5814f4dd2e130f3836fc084c894943753f",
)

# Google Test
http_archive(
  name = "com_google_googletest",
  urls = ["https://github.com/google/googletest/archive/8b6d3f9c4a774bef3081195d422993323b6bb2e0.zip"],  # 2019-03-05
  strip_prefix = "googletest-8b6d3f9c4a774bef3081195d422993323b6bb2e0",
  sha256 = "d21ba93d7f193a9a0ab80b96e8890d520b25704a6fac976fe9da81fffb3392e3",
)

# C++ rules for Bazel.
http_archive(
    name = "rules_cc",
    sha256 = "67412176974bfce3f4cf8bdaff39784a72ed709fc58def599d1f68710b58d68b",
    strip_prefix = "rules_cc-b7fe9697c0c76ab2fd431a891dbb9a6a32ed7c3e",
    urls = [
        "https://mirror.bazel.build/github.com/bazelbuild/rules_cc/archive/b7fe9697c0c76ab2fd431a891dbb9a6a32ed7c3e.zip",
        "https://github.com/bazelbuild/rules_cc/archive/b7fe9697c0c76ab2fd431a891dbb9a6a32ed7c3e.zip",
    ],
)

load("@bazel_tools//tools/build_defs/repo:http.bzl", "http_archive")

http_archive(
    name = "rules_proto",
    sha256 = "602e7161d9195e50246177e7c55b2f39950a9cf7366f74ed5f22fd45750cd208",
    strip_prefix = "rules_proto-97d8af4dc474595af3900dd85cb3a29ad28cc313",
    urls = [
        "https://mirror.bazel.build/github.com/bazelbuild/rules_proto/archive/97d8af4dc474595af3900dd85cb3a29ad28cc313.tar.gz",
        "https://github.com/bazelbuild/rules_proto/archive/97d8af4dc474595af3900dd85cb3a29ad28cc313.tar.gz",
    ],
)
load("@rules_proto//proto:repositories.bzl", "rules_proto_dependencies", "rules_proto_toolchains")
rules_proto_dependencies()
rules_proto_toolchains()

#
# new_local_repository: None-bazel
#

#
# LOCAL_FMT_REPO_BUILD = """
# cc_library(
#     name="fmtlib",
#     srcs = glob(["lib/*.a"]),
#     hdrs = glob(["include/fmt/*.h"]),
#     visibility = ["//visibility:public"],
# )"""
#

# new_local_repository(
#     name = "fmt",
#     path = "/path/to/fmt/output",  # folder contains include, lib
#     build_file = "fmt/BUILD.fmt",
# )


#
# new_git_repository: None-bazel
#

#GIT_FMT_REPO_BUILD = """
#genrule(
#    name = "fmt_genrule",
#    srcs = glob(["**/*.cc", "**/*.cpp"]),
#    outs = ["output/lib/libfmt.a"],
#    cmd = "mkdir -p build output;cd build;" +
#          "mkdir -p output;cmake .. -DCMAKE_INSTALL_PREFIX=../output ;" +
#           "make; make install",
#)
#
#cc_library(
#    name="fmtlib",
#    srcs = glob(["output/lib/*.a"]),
#    hdrs = glob(["output/include/fmt/*.h"]),
#    visibility = ["//visibility:public"],
#)
#
#"""

# new_git_repository(
#     name = "fmt",
#     remote = "https://github.com/fmtlib/fmt.git",
#     build_file = "BUILD.fmt",
#     #build_file_content = GIT_FMT_REPO_BUILD,
#     commit = "f1559e1d56a45fb7b7a23f5447173ae6b408d78c",
# )
