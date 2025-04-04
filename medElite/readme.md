# 🏥 Medelite

**Medelite** is a full-stack web application developed for a **hospital consulting service**. It serves as the company’s official platform showcasing its services, projects, and providing a channel for users to connect through a contact form.

---

## 🌐 Features

- ✅ **About Us** – Learn about the organization and its vision.
- 💡 **Why Us** – Highlights what sets Medelite apart from others in the industry.
- 📂 **Projects** – Displays previous and ongoing consulting projects.
- ✉️ **Contact Us** – A working form where users can leave inquiries and messages.
- 🔐 **Authentication** – Secure login system using Passport.js (with Google OAuth & Local strategy).
- 💾 **PostgreSQL Database** – Stores user and message data.
- 🔧 **Session Management** – Redis used for storing authenticated sessions.

---

## 🛠️ Tech Stack

- **Frontend**: HTML, CSS, JavaScript (with EJS templating)
- **Backend**: Node.js, Express.js
- **Database**: PostgreSQL
- **Authentication**: Passport.js (Google OAuth2 & Local)
- **Session Store**: Redis
- **APIs**: RESTful routes for server-client communication

---

## 🚀 How to Run Locally

### 1. 📦 Install Prerequisites
Make sure you have these installed:

- Node.js (v14+)
- PostgreSQL


### 2. 🛠️ Clone and Set Up

```bash
git clone <your-repo-url>
cd medelite-main/medelite-main
npm install
node index.js
