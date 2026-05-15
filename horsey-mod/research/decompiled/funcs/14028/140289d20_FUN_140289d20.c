// Address: 0x140289d20
// Ghidra name: FUN_140289d20
// ============ 0x140289d20 FUN_140289d20 (size=222) ============


undefined8 FUN_140289d20(undefined4 *param_1)



{

  int iVar1;

  HRESULT HVar2;

  undefined8 uVar3;

  code *pcVar4;

  undefined4 uVar5;

  undefined4 uVar6;

  undefined4 uVar7;

  undefined4 uVar8;

  

  iVar1 = FUN_1401a9990();

  if (iVar1 == 0) {

    uVar3 = FUN_14012e850("IMMDevice support requires Windows Vista or later");

    return uVar3;

  }

  iVar1 = FUN_1401a9610();

  if (iVar1 < 0) {

    uVar3 = FUN_14012e850("IMMDevice: CoInitialize() failed");

    return uVar3;

  }

  HVar2 = CoCreateInstance((IID *)&DAT_140380c58,(LPUNKNOWN)0x0,1,(IID *)&DAT_140380c68,

                           (LPVOID *)&DAT_1403fde80);

  if (HVar2 < 0) {

    CoUninitialize();

    uVar3 = FUN_1401a9ef0("IMMDevice CoCreateInstance(MMDeviceEnumerator)",HVar2);

    return uVar3;

  }

  if (param_1 == (undefined4 *)0x0) {

    uVar5 = 0;

    uVar6 = 0;

    uVar7 = 0;

    uVar8 = 0;

  }

  else {

    uVar5 = *param_1;

    uVar6 = param_1[1];

    uVar7 = param_1[2];

    uVar8 = param_1[3];

  }

  pcVar4 = (code *)CONCAT44(uVar6,uVar5);

  DAT_1403fde88 = (code *)CONCAT44(uVar6,uVar5);

  DAT_1403fde90 = (code *)CONCAT44(uVar8,uVar7);

  if (pcVar4 == (code *)0x0) {

    pcVar4 = FUN_14015d5d0;

    DAT_1403fde88 = FUN_14015d5d0;

  }

  if (DAT_1403fde90 == (code *)0x0) {

    pcVar4 = FUN_14015de70;

    DAT_1403fde90 = FUN_14015de70;

  }

  return CONCAT71((int7)((ulonglong)pcVar4 >> 8),1);

}




