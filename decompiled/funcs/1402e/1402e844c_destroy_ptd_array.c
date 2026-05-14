// Address: 0x1402e844c
// Ghidra name: destroy_ptd_array
// ============ 0x1402e844c destroy_ptd_array (size=245) ============


/* Library Function - Single Match

    void __cdecl destroy_ptd_array(struct __acrt_ptd * __ptr64 const)

   

   Libraries: Visual Studio 2015 Release, Visual Studio 2017 Release, Visual Studio 2019 Release */



void __cdecl destroy_ptd_array(__acrt_ptd *param_1)



{

  undefined1 local_res10 [8];

  undefined4 local_res18 [2];

  undefined4 local_res20 [2];

  undefined4 local_28;

  undefined4 local_24;

  __acrt_ptd *local_20;

  __acrt_ptd **local_18;

  __acrt_ptd **local_10;

  

  local_18 = &local_20;

  local_res18[0] = 5;

  local_res20[0] = 5;

  local_10 = &local_20;

  local_28 = 4;

  local_24 = 4;

  local_20 = param_1;

  if (*(undefined **)param_1 != &DAT_14038cfa0) {

    FUN_1402e9a80(*(undefined **)param_1);

  }

  FUN_1402e9a80(*(undefined8 *)(local_20 + 0x70));

  FUN_1402e9a80(*(undefined8 *)(local_20 + 0x58));

  FUN_1402e9a80(*(undefined8 *)(local_20 + 0x60));

  FUN_1402e9a80(*(undefined8 *)(local_20 + 0x68));

  FUN_1402e9a80(*(undefined8 *)(local_20 + 0x48));

  FUN_1402e9a80(*(undefined8 *)(local_20 + 0x50));

  FUN_1402e9a80(*(undefined8 *)(local_20 + 0x78));

  FUN_1402e9a80(*(undefined8 *)(local_20 + 0x80));

  FUN_1402e9a80(*(undefined8 *)(local_20 + 0x3c0));

  operator()<>(local_res10,local_res20,&local_18,local_res18);

  operator()<>(local_res10,&local_24,&local_10,&local_28);

  return;

}




