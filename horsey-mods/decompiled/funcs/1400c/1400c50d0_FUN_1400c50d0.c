// Address: 0x1400c50d0
// Ghidra name: FUN_1400c50d0
// ============ 0x1400c50d0 FUN_1400c50d0 (size=122) ============


undefined8 FUN_1400c50d0(undefined8 param_1)



{

  uint uVar1;

  uint uVar2;

  undefined *puVar3;

  _SYSTEMTIME local_20;

  

  GetLocalTime(&local_20);

  puVar3 = &DAT_14030e0cc;

  uVar2 = (uint)local_20.wHour;

  if (0xc < uVar2) {

    puVar3 = &DAT_14030e0c8;

  }

  uVar1 = local_20.wHour - 0xc;

  if (uVar2 < 0xd) {

    uVar1 = uVar2;

  }

  FUN_14008d760(param_1,"%s %d, %d:%02d %s",

                *(undefined8 *)(&DAT_1403da6d8 + (ulonglong)local_20.wMonth * 8),local_20.wDay,uVar1

                ,local_20.wMinute,puVar3);

  return param_1;

}




