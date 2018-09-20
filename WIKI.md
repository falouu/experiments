
* Permissions
  * Even if `setuid` is set, user without *execute* permission cannot execute it
    
    For example:
      
      ```bash
    > ls -l executable
    -rws------  1 owner owner 9520 Sep 20 21:22 executable
    
    > id
    uid=1001(caller) gid=1001(caller) groups=1001(caller)
    
    > ./executable
    bash: ./executable: Permission denied
      ```
  * with `o+x` permission everyone can execute file
     
    ```bash
    > chmod 4701 executable
    > ./executable
    Running...
    ```
  
* `chmod 4xxx` - set `setuid` flag (replace `xxx` with actual 3 digit permissions)

* Test 1: `setuid` with non-root file owner
  * `setuid(geteuid())` do nothing, as i would expect!
