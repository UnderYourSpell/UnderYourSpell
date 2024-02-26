#Test Workload for OS

set $nthreads=2

define fileset name="testF",entries=100,filesize=1k,prealloc,path="/tmp"

  define process name="readerP",instances=1 {
    thread name="readerT",instances=$nthreads {
      flowop openfile name="openOP",filesetname="testF"
      flowop readwholefile name="readOP",filename="testF"
      flowop closefile name="closeOP"
    }
  }

run 60

