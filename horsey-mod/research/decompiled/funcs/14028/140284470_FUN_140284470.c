// Address: 0x140284470
// Ghidra name: FUN_140284470
// ============ 0x140284470 FUN_140284470 (size=287) ============


undefined8 FUN_140284470(longlong param_1)



{

  longlong *plVar1;

  undefined8 uVar2;

  int iVar3;

  

  thunk_FUN_140180060(2);

  iVar3 = FUN_140138fe0(param_1 + 4);

  while (iVar3 != 0) {

    FUN_140163d70(*(undefined8 *)(param_1 + 0x10));

    FUN_140179b40(DAT_1403fddb8);

    plVar1 = *(longlong **)(param_1 + 0x20);

    if (plVar1 == (longlong *)0x0) {

      FUN_140179b60(DAT_1403fddb8);

    }

    else {

      if (plVar1 == *(longlong **)(param_1 + 0x18)) {

        *(undefined8 *)(param_1 + 0x18) = 0;

      }

      uVar2 = DAT_1403fddb8;

      *(longlong *)(param_1 + 0x20) = plVar1[0x14];

      FUN_140179b60(uVar2);

      FUN_140179b40(*(undefined8 *)(*plVar1 + 0x78));

      if (*(longlong *)(*plVar1 + 0x80) != 0) {

        FUN_140195730(*(longlong *)(*plVar1 + 0x80),plVar1 + 1,(longlong)(int)plVar1[0x11]);

      }

      FUN_140179b60(*(undefined8 *)(*plVar1 + 0x78));

      if ((code *)plVar1[0x12] != (code *)0x0) {

        (*(code *)plVar1[0x12])(plVar1[0x13]);

      }

      FUN_140138fb0(*plVar1 + 0x88,0xffffffff);

      FUN_1401841e0(plVar1);

      FUN_1401492f0(10);

    }

    iVar3 = FUN_140138fe0(param_1 + 4);

  }

  return 0;

}




