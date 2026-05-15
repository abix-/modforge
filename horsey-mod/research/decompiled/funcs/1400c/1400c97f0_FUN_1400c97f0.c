// Address: 0x1400c97f0
// Ghidra name: FUN_1400c97f0
// ============ 0x1400c97f0 FUN_1400c97f0 (size=390) ============


void FUN_1400c97f0(undefined8 *param_1)



{

  undefined8 *puVar1;

  longlong lVar2;

  ulonglong uVar3;

  ulonglong uVar4;

  uint uVar5;

  ulonglong uVar6;

  

  uVar4 = 0;

  *param_1 = &PTR_FUN_14030e6f8;

  lVar2 = param_1[0x17];

  uVar3 = uVar4;

  uVar6 = uVar4;

  if (param_1[0x18] - lVar2 >> 3 != 0) {

    do {

      puVar1 = *(undefined8 **)(uVar3 + lVar2);

      if (puVar1 != (undefined8 *)0x0) {

        (**(code **)*puVar1)(puVar1,1);

      }

      lVar2 = param_1[0x17];

      uVar5 = (int)uVar6 + 1;

      uVar3 = uVar3 + 8;

      uVar6 = (ulonglong)uVar5;

    } while ((ulonglong)(longlong)(int)uVar5 < (ulonglong)(param_1[0x18] - lVar2 >> 3));

  }

  lVar2 = param_1[0x26];

  uVar3 = uVar4;

  if (param_1[0x27] - lVar2 >> 3 != 0) {

    do {

      puVar1 = *(undefined8 **)(uVar4 + lVar2);

      if (puVar1 != (undefined8 *)0x0) {

        (**(code **)*puVar1)(puVar1,1);

      }

      lVar2 = param_1[0x26];

      uVar5 = (int)uVar3 + 1;

      uVar4 = uVar4 + 8;

      uVar3 = (ulonglong)uVar5;

    } while ((ulonglong)(longlong)(int)uVar5 < (ulonglong)(param_1[0x27] - lVar2 >> 3));

  }

  lVar2 = param_1[0x49];

  if (lVar2 != 0) {

    FUN_1400c8d80(lVar2);

    FUN_1402c7088(lVar2,0x1f48);

  }

  if (param_1[0x2a] != 0) {

    FUN_1402c7088(param_1[0x2a],0x1e0);

  }

  FUN_140087ec0(param_1 + 0x42);

  FUN_140087ec0(param_1 + 0x3c);

  FUN_140030810(param_1 + 0x26);

  FUN_140030810(param_1 + 0x17);

  FUN_1400371c0(param_1 + 0xf);

  FUN_1400d8950(param_1 + 0xc);

  FUN_140027900(param_1 + 7);

  FUN_140027900(param_1 + 3);

  *param_1 = b2ContactFilter::vftable;

  return;

}




