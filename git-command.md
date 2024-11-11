# A Quick Guide to Git Commands for Collaboration

### 1. Initialize the Project
`git clone git@github.com:SeeChen/WanderSnap.git`
> Clone the repository to your local machine.

### 2. Create a feature branch
`git checkout -b <feature_branch>`
> Create a new branch to avoid code conflicts.

#### 2.1 Check all branch
`git branch -a`
> Confirm that the branch has been created.

### 3. Sync your work
#### 3.1 Add Files to Staging
`git add <file_name>`
> Add updated files to staging. Use `git add .` to stage all files that are not marked in ***.gitignore***.

#### 3.2 Commit Your Changes
`git commit -m "<your_message>"`
> Commit the changes in the staging area to the local repository. Use *your_message* to describe what you did.

#### 3.3 Push to your branch
`git push -u origin <feature_branch>`
> Push your changes to the remote branch. You can check your current branch with `git status`.

### 4 Submit a Pull Request (PR)
`git request-pull main git@github.com:SeeChen/WanderSnap.git`
> Send a **PR** to the administrator to integrate your code. If you don't know your repository_url, check it using `git remote -v`.

### 5. Pull from Remote
#### 5.1 Fetch the latest changes from the remote repository
`git fetch origin`
> This command downloads the latest changes from the remote repository without merging them into your local branch.

#### 5.2 Merge the fetched changes into your current branch
`git merge origin/<branch_name>`
> This merges the latest changes from the specified remote branch (e.g., `main`) into your local branch. Make sure to replace `<branch_name>` with the actual branch name you want to merge from (e.g., `main`).

---
<div align="right">

###### *Last Modified by [SeeChen](https://github.com/SeeChen/) @ 10-NOV-2024 23:47 UTC +08:00*
</div>
