rsync -avz -L rohanraja@192.168.1.110:/home/rohanraja/code/cgt/share $HOME/

function addkey(){
  ssh-keygen
  ssh-copy-id -i ~/.ssh/id_rsa.pub rohanraja@192.168.1.110
}
