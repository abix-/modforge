// Address: 0x140221ba0
// Ghidra name: FUN_140221ba0
// ============ 0x140221ba0 FUN_140221ba0 (size=201) ============


void FUN_140221ba0(longlong param_1,longlong param_2,longlong param_3,longlong *param_4)



{

  undefined4 uVar1;

  longlong lVar2;

  char cVar3;

  longlong lVar4;

  uint uVar5;

  longlong lVar6;

  undefined1 *puVar7;

  uint local_48 [12];

  

  cVar3 = (**(code **)(*param_4 + 0x80))(param_4,local_48);

  if (cVar3 != '\0') {

    lVar2 = *(longlong *)(param_1 + 0x30);

    lVar4 = (**(code **)(*param_4 + 0x28))(param_4);

    uVar1 = *(undefined4 *)(param_3 + 0x18);

    puVar7 = &DAT_140356300;

    lVar6 = 7;

    uVar5 = 1;

    do {

      FUN_1401628d0((lVar4 + lVar2) * 1000,param_2,uVar1,*puVar7,(local_48[0] & uVar5) != 0);

      uVar5 = uVar5 << 1 | (uint)((int)uVar5 < 0);

      puVar7 = puVar7 + 1;

      lVar6 = lVar6 + -1;

    } while (lVar6 != 0);

    *(undefined8 *)(*(longlong *)(param_2 + 0x188) + 0x50) = 0xffffffffffffffff;

  }

  return;

}




