// Address: 0x1402dfea0
// Ghidra name: FUN_1402dfea0
// ============ 0x1402dfea0 FUN_1402dfea0 (size=83) ============


ulonglong FUN_1402dfea0(longlong param_1,undefined8 param_2)



{

  byte bVar1;

  byte *pbVar2;

  int iVar3;

  

  do {

    pbVar2 = *(byte **)(param_1 + 0x10);

    if (pbVar2 == *(byte **)(param_1 + 8)) {

      return 0xffffffff;

    }

    bVar1 = *pbVar2;

    *(byte **)(param_1 + 0x10) = pbVar2 + 1;

    iVar3 = FUN_1402d8964((ulonglong)bVar1,8,param_2);

  } while (iVar3 != 0);

  return (ulonglong)bVar1;

}




