// Address: 0x1402303d0
// Ghidra name: FUN_1402303d0
// ============ 0x1402303d0 FUN_1402303d0 (size=143) ============


undefined1 FUN_1402303d0(undefined8 param_1,longlong param_2)



{

  undefined8 *puVar1;

  undefined1 uVar2;

  int iVar3;

  undefined4 local_18 [2];

  undefined8 uStack_10;

  

  local_18[0] = 0;

  puVar1 = *(undefined8 **)(*(longlong *)(param_2 + 0x10) + 0x30);

  uStack_10 = param_1;

  FUN_140179b40(*puVar1);

  iVar3 = (*DAT_1403fdda8)(puVar1[3],local_18,0,param_2,0);

  if (iVar3 < 0) {

    uVar2 = FUN_1401a9ef0("BuildIoRingFlushFile",iVar3);

  }

  else {

    uVar2 = (*(code *)**(undefined8 **)(param_2 + 0x10))

                      ((*(undefined8 **)(param_2 + 0x10))[6],param_2);

  }

  FUN_140179b60(*puVar1);

  return uVar2;

}




