# Getting started

## Pre requisites
- [Git](https://git-scm.com/download/win)

## Clone the project

### Generate your SSH Key
First you must generate your ssh key, to do this you have to open the "Git Bash" and run the following command:

```bash
$ ssh-keygen
```

This will prompt the next:
```shell
Generating public/private rsa key pair.
Enter file in which to save the key (/c/Users/{YOUR_USER}/.ssh/id_rsa):
```
Press enter and after that you will be asked for your passphrase, which is basically the password you will use to protect the ssh connections (but you may left this blank):
```shell
Enter passphrase (empty for no passphrase):
Enter same passphrase again:
```
Finally you will see an output similar to this:
```sehl
Your identification has been saved in /c/Users/{YOUR_USER}/.ssh/id_rsa.
Your public key has been saved in /c/Users/{YOUR_USER}/.ssh/id_rsa.pub.
The key fingerprint is:
SHA256:EqNMXiXx66zUcpH+CMYIqHqwooHuyHNPENVvfK6pHSG {YOUR_USER}@{YOUR_PC_NAME}
The key's randomart image is:
+---[RSA 2048]----+
|     =. ....     |
|  .  =.  .  .    |
| . o.=. .    o   |
|. o. + . .    + .|
| +  =o=     ...o |
|. +++=.B   . . ..|
|o +oo.=     . .o |
|o++ +. o   . oo. |
|E. . o.   . o..  |
+----[SHA256]-----+
```

### Clone the repository using MPLAB X
To perform this action in MPLAB X go to:
```
Team > Git > Clone
```
Then in the clone window you must use the GitLab repository link (git@gitlab.com:haiteku/agv_fw.git) and check that the other fields looks like in the next image:
![Captura1](https://c4b021d69a7.haiteku.mx/Captura.PNG)

Note: If you set a passphrase you must write it on the indicated field and check the "Save Passphrase" box.

Then press "Next" and verify that the info looks like the next image:
![Captura2](https://c4b021d69a7.haiteku.mx/Captura2.PNG)

Note: More than one branch may appear on this window, if thats the case and no one of the listed branches belongs to you only check the "master*" branch.

Finally you will se the nex window:

![Captura3](https://c4b021d69a7.haiteku.mx/Captura3.PNG)

Press "Finish" button and the repository would be cloned.

## Switching your branch
Once you have cloned the repository you must switch to your development branch, to do this (having selected the project on the "Projects" tab) go to:
```
Team > Branch/Tag > Switch to branch
```

And select your brnch from the list or select "Checkout as New Branch" and create a new one.

After this step you can start developing on the project.