// Address: 0x140170cc0
// Ghidra name: FUN_140170cc0
// ============ 0x140170cc0 FUN_140170cc0 (size=323) ============


ulonglong FUN_140170cc0(longlong param_1,char param_2)



{

  char cVar1;

  byte bVar2;

  ulonglong uVar3;

  ulonglong uVar4;

  

  if (DAT_1403fc410 == 0) {

    uVar3 = FUN_1401730c0();

    return uVar3 & 0xffffffffffffff00;

  }

  if ((param_1 == 0) ||

     ((DAT_1403e3d60 != '\0' && (cVar1 = FUN_1401aa7c0(param_1,1), cVar1 == '\0')))) {

    uVar3 = FUN_14012e850("Invalid window");

    return uVar3 & 0xffffffffffffff00;

  }

  if ((*(ulonglong *)(param_1 + 0x48) & 0xc0000) != 0) {

    uVar3 = FUN_14012e850("Operation invalid on popup windows");

    return uVar3 & 0xffffffffffffff00;

  }

  if ((*(ulonglong *)(param_1 + 0x48) & 8) != 0) {

    uVar4 = *(ulonglong *)(param_1 + 0x50) & 0xfffffffffffffffe;

    uVar3 = *(ulonglong *)(param_1 + 0x50) | 1;

    if (param_2 == '\0') {

      uVar3 = uVar4;

    }

    *(ulonglong *)(param_1 + 0x50) = uVar3;

    return CONCAT71((int7)(uVar4 >> 8),1);

  }

  if (param_2 == '\0') {

    bVar2 = FUN_140173190(param_1,0,1);

LAB_140170db4:

    *(undefined8 *)(param_1 + 200) = 0;

    *(undefined8 *)(param_1 + 0xd0) = 0;

    *(undefined8 *)(param_1 + 0xd8) = 0;

    *(undefined8 *)(param_1 + 0xe0) = 0;

    *(undefined8 *)(param_1 + 0xe8) = 0;

    if (bVar2 == 0) goto LAB_140170ddb;

  }

  else {

    *(undefined8 *)(param_1 + 200) = *(undefined8 *)(param_1 + 0xa0);

    *(undefined8 *)(param_1 + 0xd0) = *(undefined8 *)(param_1 + 0xa8);

    *(undefined4 *)(param_1 + 0xd8) = *(undefined4 *)(param_1 + 0xb0);

    *(undefined4 *)(param_1 + 0xdc) = *(undefined4 *)(param_1 + 0xb4);

    *(undefined4 *)(param_1 + 0xe0) = *(undefined4 *)(param_1 + 0xb8);

    *(undefined4 *)(param_1 + 0xe4) = *(undefined4 *)(param_1 + 0xbc);

    *(undefined8 *)(param_1 + 0xe8) = *(undefined8 *)(param_1 + 0xc0);

    bVar2 = FUN_140173190(param_1,1,1);

    if (bVar2 == 0) goto LAB_140170db4;

  }

  FUN_140172f30(param_1);

LAB_140170ddb:

  return (ulonglong)bVar2;

}




