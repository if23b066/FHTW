git branch development
git checkout development
git diff
git reset --soft HEAD~1
git reset --hard HEAD~1
touch .gitignore
git branch -b featureA
git branch -b hotfix
git merge hotfix
git merge --no-ff featureA
git branch -d featureA