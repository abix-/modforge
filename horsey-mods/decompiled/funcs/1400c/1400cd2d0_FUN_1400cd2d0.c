// Address: 0x1400cd2d0
// Ghidra name: FUN_1400cd2d0
// ============ 0x1400cd2d0 FUN_1400cd2d0 (size=640) ============


void FUN_1400cd2d0(longlong param_1)



{

  longlong *plVar1;

  undefined4 uVar2;

  undefined4 uVar3;

  float fVar4;

  int iVar5;

  char local_58 [8];

  char local_50 [4];

  char local_4c;

  undefined1 local_4b;

  undefined2 local_4a;

  undefined8 local_48;

  undefined8 local_40;

  

  uVar2 = DAT_140303354;

  if ((*(int *)(param_1 + 0xd4) != -1) &&

     (plVar1 = *(longlong **)

                (*(longlong *)(param_1 + 0xb8) + (longlong)*(int *)(param_1 + 0xd4) * 8),

     (int)plVar1[1] == 3)) {

    (**(code **)(*plVar1 + 0x30))(plVar1,DAT_140303354);

    iVar5 = FUN_14005e250(*(undefined4 *)((longlong)plVar1 + 0xc));

    if ((iVar5 == -1) ||

       (((*(int *)(param_1 + 0x15c) == -1 || (*(int *)(param_1 + 0x124) == 0xf)) ||

        (*(int *)(param_1 + 0x124) == 0x10)))) {

      DAT_1403f3a0c = 0;

    }

    else {

      if (*(int *)(*(longlong *)((longlong)ThreadLocalStoragePointer + (ulonglong)_tls_index * 8) +

                  4) < DAT_1403f3a14) {

        FUN_1402c7138(&DAT_1403f3a14);

        if (DAT_1403f3a14 == -1) {

          local_4a = 0;

          local_48 = 0xd;

          local_40 = 0xf;

          local_58[0] = s_PointerAttach_140303fa0[0];

          local_58[1] = s_PointerAttach_140303fa0[1];

          local_58[2] = s_PointerAttach_140303fa0[2];

          local_58[3] = s_PointerAttach_140303fa0[3];

          local_58[4] = s_PointerAttach_140303fa0[4];

          local_58[5] = s_PointerAttach_140303fa0[5];

          local_58[6] = s_PointerAttach_140303fa0[6];

          local_58[7] = s_PointerAttach_140303fa0[7];

          local_50[0] = s_PointerAttach_140303fa0[8];

          local_50[1] = s_PointerAttach_140303fa0[9];

          local_50[2] = s_PointerAttach_140303fa0[10];

          local_50[3] = s_PointerAttach_140303fa0[0xb];

          local_4c = s_PointerAttach_140303fa0[0xc];

          local_4b = 0;

          DAT_1403f3a10 = FUN_14006fe60(local_58);

          _Init_thread_footer(&DAT_1403f3a14);

        }

      }

      fVar4 = DAT_14039ca34;

      DAT_1403f3a0c = DAT_1403f3a0c + 1;

      if (DAT_1403f3a0c % 10 < 5) {

        FUN_140071ed0(DAT_1403f3a10,*(float *)(plVar1 + 5) - *(float *)(plVar1 + 6) * DAT_14039ca34,

                      *(float *)((longlong)plVar1 + 0x2c) -

                      *(float *)((longlong)plVar1 + 0x34) * DAT_14039ca34,uVar2,uVar2);

        uVar3 = DAT_14030375c;

        FUN_140071ed0(DAT_1403f3a10,*(float *)(plVar1 + 6) * fVar4 + *(float *)(plVar1 + 5),

                      *(float *)((longlong)plVar1 + 0x2c) -

                      *(float *)((longlong)plVar1 + 0x34) * fVar4,DAT_14030375c,uVar2);

        FUN_140071ed0(DAT_1403f3a10,*(float *)(plVar1 + 5) - *(float *)(plVar1 + 6) * fVar4,

                      *(float *)((longlong)plVar1 + 0x34) * fVar4 +

                      *(float *)((longlong)plVar1 + 0x2c),uVar2,uVar3);

        FUN_140071ed0(DAT_1403f3a10,*(float *)(plVar1 + 6) * fVar4 + *(float *)(plVar1 + 5),

                      *(float *)((longlong)plVar1 + 0x34) * fVar4 +

                      *(float *)((longlong)plVar1 + 0x2c),uVar3,uVar3);

      }

      *(undefined4 *)(param_1 + 0x16c) = *(undefined4 *)(param_1 + 0x15c);

    }

  }

  return;

}




