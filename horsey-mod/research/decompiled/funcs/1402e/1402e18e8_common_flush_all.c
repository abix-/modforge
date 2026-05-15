// Address: 0x1402e18e8
// Ghidra name: common_flush_all
// ============ 0x1402e18e8 common_flush_all (size=93) ============


/* Library Function - Single Match

    int __cdecl common_flush_all(bool)

   

   Libraries: Visual Studio 2017 Release, Visual Studio 2019 Release */



int __cdecl common_flush_all(bool param_1)



{

  char local_res8 [8];

  undefined1 local_res10 [8];

  int local_res18 [2];

  int local_res20 [2];

  undefined4 local_28;

  undefined4 local_24;

  int *local_20;

  char *local_18;

  int *local_10;

  

  local_res20[0] = 0;

  local_20 = local_res20;

  local_res18[0] = 0;

  local_18 = local_res8;

  local_10 = local_res18;

  local_28 = 8;

  local_24 = 8;

  local_res8[0] = param_1;

  FUN_1402e17c4(local_res10,&local_24,&local_20,&local_28);

  if (local_res8[0] != '\0') {

    local_res18[0] = local_res20[0];

  }

  return local_res18[0];

}




