// Address: 0x1402302f0
// Ghidra name: FUN_1402302f0
// ============ 0x1402302f0 FUN_1402302f0 (size=221) ============


ulonglong FUN_1402302f0(undefined8 param_1,longlong param_2)



{

  undefined8 *puVar1;

  byte bVar2;

  int iVar3;

  ulonglong uVar4;

  undefined4 local_28 [2];

  undefined8 uStack_20;

  undefined4 local_18 [2];

  undefined8 uStack_10;

  

  if (0xffffffff < *(ulonglong *)(param_2 + 0x40)) {

    uVar4 = FUN_14012e850("ioring: i/o task is too large");

    return uVar4;

  }

  puVar1 = *(undefined8 **)(*(longlong *)(param_2 + 0x10) + 0x30);

  uStack_20 = *(undefined8 *)(param_2 + 0x28);

  local_18[0] = 0;

  local_28[0] = 0;

  uStack_10 = param_1;

  FUN_140179b40(*puVar1);

  iVar3 = (*DAT_1403fdda0)(puVar1[3],local_18,local_28,*(undefined4 *)(param_2 + 0x40),

                           *(undefined8 *)(param_2 + 0x18),0,param_2,0);

  if (iVar3 < 0) {

    bVar2 = FUN_1401a9ef0("BuildIoRingWriteFile",iVar3);

  }

  else {

    bVar2 = (*(code *)**(undefined8 **)(param_2 + 0x10))

                      ((*(undefined8 **)(param_2 + 0x10))[6],param_2);

  }

  FUN_140179b60(*puVar1);

  return (ulonglong)bVar2;

}




