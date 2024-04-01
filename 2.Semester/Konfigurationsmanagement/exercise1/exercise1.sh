git init
--
git config --global user.name "if23b06"
git config --global user.email "if23b066@technikum-wien.at"
--
touch <file_name>
vim <file_name>
--
git status
--
git add <file_name>
--
git hash-object <file_name>
--
git cat-file -p <SHA-key>
git show <SHA-key>
--
echo -n "Hello World!" | git hash-object --stdin
--
echo -n "Hello World!" | git hash-object -w --stdin
--
git log
git commit -m "<comment>"
--
git config --global alias.lol „log --graph --decorate --oneline --all“
--
git commit --amend
--
git rm <file_name>
git checkout <hash_code>