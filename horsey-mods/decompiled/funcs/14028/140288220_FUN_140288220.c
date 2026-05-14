// Address: 0x140288220
// Ghidra name: FUN_140288220
// ============ 0x140288220 FUN_140288220 (size=204) ============


ulonglong FUN_140288220(undefined4 *param_1,longlong param_2)



{

  longlong *plVar1;

  undefined4 *puVar2;

  int iVar3;

  ulonglong uVar4;

  undefined8 uVar5;

  undefined4 local_458;

  undefined1 local_454 [1100];

  

  local_458 = 0x44c;

  plVar1 = *(longlong **)(*(longlong *)(param_2 + 0x148) + 0x10);

  uVar4 = (**(code **)(*plVar1 + 0x78))(plVar1,&local_458);

  puVar2 = DAT_1403fdb58;

  if ((int)uVar4 < 0) {

    return uVar4 & 0xffffffffffffff00;

  }

  while( true ) {

    if (puVar2 == (undefined4 *)0x0) {

      uVar4 = FUN_14012e850("Couldn\'t find joystick in haptic device list");

      return uVar4;

    }

    iVar3 = FUN_1401a98e0(puVar2 + 7,local_454);

    if (iVar3 != 0) break;

    puVar2 = *(undefined4 **)(puVar2 + 0x124);

  }

  *param_1 = *puVar2;

  uVar5 = FUN_14012f0d0(*(undefined8 *)(puVar2 + 2));

  *(undefined8 *)(param_1 + 2) = uVar5;

  uVar4 = FUN_140287f60(param_1,*(undefined8 *)(*(longlong *)(param_2 + 0x148) + 0x10),1);

  return uVar4;

}




