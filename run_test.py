#!/usr/bin/env python3
import os
import subprocess
import json


def find_shortest(names):
    rtn = 0
    for name in names:
        if len(name) > rtn:
            rtn = len(name)
    return rtn


def main():
    if not os.path.isdir("build"):
        os.mkdir("build")

    # build
    print("Building...")
    subprocess.check_output("cd build && cmake .. && make", shell=True)

    # run test
    print("Running test...")
    if not os.path.isfile("test_detail.json") or os.path.getctime(
        "test_detail.json"
    ) < os.path.getctime("build/performance_test"):
        print("Test result is too old. Rerunning ...")
        subprocess.check_output(
            "build/performance_test --gtest_output=json", shell=True
        )

    # format output as Markdown
    print("Formatting output...")
    names = []
    times = []
    with open("test_detail.json", "r", encoding="utf8") as f:
        root = json.load(f)

    suites = root["testsuites"]
    for suite in suites:
        names.append(suite["name"] + "*" * 4)
        times.append(suite["time"] + "*" * 4)
        for s in suite["testsuite"]:
            names.append(s["name"])
            times.append(s["time"])

    name_len = find_shortest(names)
    time_len = find_shortest(times)

    print(f"| {'Test':>{name_len}} | {'Time':>{time_len}} |")
    print(f"| {'-'*name_len} | {'-'*time_len} |")

    for suite in suites:
        name = "**" + suite["name"] + "**"
        time = "**" + suite["time"] + "**"
        print(f"| {name:<{name_len}} | {time:>{time_len}} |")
        for s in suite["testsuite"]:
            name = s["name"]
            time = s["time"]
            print(f"| {name:<{name_len}} | {time:>{time_len}} |")


if __name__ == "__main__":
    main()
