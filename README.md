# 🌱 Nexus Log 

![Build Status](https://img.shields.io/badge/build-passing-brightgreen)
![Tech Stack](https://img.shields.io/badge/stack-Next.js_14_%7C_TypeScript_%7C_Tailwind-000000)
![Status](https://img.shields.io/badge/status-active_development-blue)

> **"The operating system for my thoughts."**

**Nexus Log** is a high-performance Digital Garden and Personal Knowledge Management (PKM) system designed for lifetime learning. It functions as a self-hosted "Second Brain" that visualizes knowledge connections, tracks study analytics, and organizes daily learnings into a searchable, navigable archive.

**[🌐 Live Interface](https://nexuslog.vercel.app/)**

---

## 🚀 Key Features

### 🕸️ Contextual Intelligence
* **Bidirectional Linking:** Implements `[[Wikilinks]]` logic to create an auto-generating web of thoughts.
* **Interactive Graph:** Powered by `react-force-graph`, allowing for spatial exploration of knowledge clusters.
* **Backlinks:** Automatically aggregates all references to the current topic.

### 📊 Deep Analytics
* **Study Heatmap:** GitHub-style activity grid tracking daily learning intensity.
* **Topic Radar:** Visual breakdown of disciplines (e.g., 40% CS, 30% Physics, 10% Philosophy).
* **Velocity Tracking:** Charts displaying the rate of new concept acquisition over time.

### ⏳ Temporal Architecture
* **Time Travel:** Hierarchical archive allows browsing by `Year > Month > Day`.
* **Daily Journals:** Date-centric workflow for capturing day-to-day progress.
* **Timeline View:** Linear visualization of knowledge acquisition history.

### 🧪 Scholar's Toolkit
* **LaTeX Support:** Native rendering of complex math equations ($E=mc^2$) via KaTeX.
* **Code Syntax Highlighting:** Prism-powered code blocks for storing algorithms and snippets.
* **Fuzzy Search:** `Cmd+K` global command palette for instant access to any concept.

---

## 🛠️ Technical Architecture

**Nexus Log** uses a **"Local-First, Git-Based"** architecture. It abandons traditional databases in favor of a flat-file Markdown system, ensuring data ownership and longevity.

* **Frontend:** Next.js 14 (App Router)
* **Styling:** Tailwind CSS + Shadcn UI
* **Visualization:** React Force Graph (2D/3D), Recharts
* **Content Engine:** MDX + Remark/Rehype Plugins
* **Deployment:** Vercel Edge Network

### The Sync Workflow
1.  **Local Admin:** I write notes locally in a secure Admin Interface.
2.  **Git-State:** The app commits changes directly to the Git history.
3.  **CI/CD:** Vercel detects the commit, rebuilds the static graph, and updates the live site.
