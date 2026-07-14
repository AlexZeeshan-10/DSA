#!/usr/bin/env python3
import os
import glob

print("Updating Progress Tracker in Readme.md...")

dirs = [d for d in os.listdir('.') if os.path.isdir(d) and not d.startswith('.') and d != 'scripts']
dirs.sort()

table_lines = [
    "",
    "| Topic | Problems Solved |",
    "|-------|-----------------|"
]

total = 0
for d in dirs:
    cpp_files = glob.glob(f"{d}/**/*.cpp", recursive=True)
    count = len(cpp_files)
    if count > 0:
        table_lines.append(f"| {d} | {count} |")
        total += count

if total == 0:
    print("No .cpp files found.")
    exit(0)

table_lines.append(f"| **Total** | **{total}** |")
table_lines.append("")

table_content = "\n".join(table_lines)

with open('Readme.md', 'r', encoding='utf-8') as f:
    content = f.read()

start_marker = "<!-- PROGRESS_TRACKER_START -->"
end_marker = "<!-- PROGRESS_TRACKER_END -->"

start_idx = content.find(start_marker)
end_idx = content.find(end_marker)

if start_idx != -1 and end_idx != -1:
    new_content = content[:start_idx + len(start_marker)] + "\n" + table_content + "\n" + content[end_idx:]
    with open('Readme.md', 'w', encoding='utf-8') as f:
        f.write(new_content)
    print("Progress Tracker updated successfully!")
else:
    print("Markers not found in Readme.md")
    exit(1)
