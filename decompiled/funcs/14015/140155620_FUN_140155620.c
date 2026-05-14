// Address: 0x140155620
// Ghidra name: FUN_140155620
// ============ 0x140155620 FUN_140155620 (size=147) ============


void FUN_140155620(longlong param_1)



{

  undefined4 *puVar1;

  char cVar2;

  undefined4 local_res8 [2];

  undefined8 local_res10;

  undefined8 local_18;

  undefined4 local_10;

  undefined4 local_c;

  

  puVar1 = *(undefined4 **)(param_1 + 0xf8);

  local_res10 = 0;

  local_res8[0] = 0;

  local_18 = 0;

  local_10 = *(undefined4 *)(param_1 + 4);

  local_c = *(undefined4 *)(param_1 + 8);

  cVar2 = FUN_14014f910(puVar1,&local_18,&local_res10,local_res8);

  if (cVar2 != '\0') {

    FUN_140205a00(*(undefined8 *)(param_1 + 0x100),&local_18,*puVar1,local_10,local_c,local_res10,

                  local_res8[0]);

    FUN_1401556c0(puVar1);

  }

  return;

}




