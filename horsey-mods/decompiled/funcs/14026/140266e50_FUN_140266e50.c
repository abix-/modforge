// Address: 0x140266e50
// Ghidra name: FUN_140266e50
// ============ 0x140266e50 FUN_140266e50 (size=318) ============


void FUN_140266e50(undefined8 *param_1)



{

  longlong lVar1;

  longlong lVar2;

  short sVar3;

  

  lVar1 = 0;

  sVar3 = 0x45e;

  lVar2 = lVar1;

  while (((sVar3 != *(short *)(*(longlong *)*param_1 + 0x20) ||

          (*(short *)((longlong)&DAT_14037df92 + lVar1) != *(short *)(*(longlong *)*param_1 + 0x22))

          ) || ((&DAT_14037df94)[lVar1] != *(char *)(param_1 + 1)))) {

    lVar2 = lVar2 + 1;

    lVar1 = lVar2 * 0x5c;

    sVar3 = *(short *)(&DAT_14037df90 + lVar1);

    if (sVar3 == 0) {

      return;

    }

  }

  lVar2 = lVar2 * 0x5c;

  *(uint *)((longlong)param_1 + 0x14c) =

       *(uint *)((longlong)param_1 + 0x14c) | *(uint *)(&UNK_14037df98 + lVar2);

  *(uint *)((longlong)param_1 + 0x14c) =

       *(uint *)((longlong)param_1 + 0x14c) & ~*(uint *)(&UNK_14037df9c + lVar2);

  *(undefined4 *)(param_1 + 0x2a) = *(undefined4 *)(&UNK_14037dfa0 + lVar2);

  *(undefined4 *)((longlong)param_1 + 0x144) = *(undefined4 *)(&UNK_14037dfe4 + lVar2);

  *(uint *)((longlong)param_1 + 0x5c) =

       *(uint *)((longlong)param_1 + 0x5c) | *(uint *)(&UNK_14037dfa4 + lVar2);

  *(uint *)((longlong)param_1 + 0x7c) =

       *(uint *)((longlong)param_1 + 0x7c) | *(uint *)(&UNK_14037dfc4 + lVar2);

  *(uint *)(param_1 + 0xc) = *(uint *)(param_1 + 0xc) | *(uint *)(&UNK_14037dfa8 + lVar2);

  *(uint *)(param_1 + 0x10) = *(uint *)(param_1 + 0x10) | *(uint *)(&UNK_14037dfc8 + lVar2);

  *(uint *)((longlong)param_1 + 100) =

       *(uint *)((longlong)param_1 + 100) | *(uint *)(&UNK_14037dfac + lVar2);

  *(uint *)((longlong)param_1 + 0x84) =

       *(uint *)((longlong)param_1 + 0x84) | *(uint *)(&UNK_14037dfcc + lVar2);

  *(uint *)(param_1 + 0xd) = *(uint *)(param_1 + 0xd) | *(uint *)(&UNK_14037dfb0 + lVar2);

  *(uint *)(param_1 + 0x11) = *(uint *)(param_1 + 0x11) | *(uint *)(&UNK_14037dfd0 + lVar2);

  *(uint *)((longlong)param_1 + 0x6c) =

       *(uint *)((longlong)param_1 + 0x6c) | *(uint *)(&UNK_14037dfb4 + lVar2);

  *(uint *)((longlong)param_1 + 0x8c) =

       *(uint *)((longlong)param_1 + 0x8c) | *(uint *)(&UNK_14037dfd4 + lVar2);

  *(uint *)(param_1 + 0xe) = *(uint *)(param_1 + 0xe) | *(uint *)(&UNK_14037dfb8 + lVar2);

  *(uint *)(param_1 + 0x12) = *(uint *)(param_1 + 0x12) | *(uint *)(&UNK_14037dfd8 + lVar2);

  *(uint *)((longlong)param_1 + 0x74) =

       *(uint *)((longlong)param_1 + 0x74) | *(uint *)(&UNK_14037dfbc + lVar2);

  *(uint *)((longlong)param_1 + 0x94) =

       *(uint *)((longlong)param_1 + 0x94) | *(uint *)(&UNK_14037dfdc + lVar2);

  *(uint *)(param_1 + 0xf) = *(uint *)(param_1 + 0xf) | *(uint *)(&UNK_14037dfc0 + lVar2);

  *(uint *)(param_1 + 0x13) = *(uint *)(param_1 + 0x13) | *(uint *)(&UNK_14037dfe0 + lVar2);

  *(uint *)(param_1 + 0x2b) = (uint)(byte)(&UNK_14037dfe8)[lVar2];

  *(uint *)((longlong)param_1 + 0x15c) = (uint)(byte)(&UNK_14037dfe9)[lVar2];

  return;

}




