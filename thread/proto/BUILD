load("@rules_proto//proto:defs.bzl", "proto_library")
load("@rules_cc//cc:defs.bzl", "cc_proto_library")

# package(default_visibility=["//:public"])

proto_library(
    name="person",
    srcs=["test.proto"],
    #visibility = ["//__pkg__"],
    visibility = ["//visibility:public"],
)

cc_proto_library(
    name="person_cc_proto",
    deps=[":person"],
    visibility = ["//visibility:public"],
)
