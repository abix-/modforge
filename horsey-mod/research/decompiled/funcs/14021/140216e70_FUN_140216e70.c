// Address: 0x140216e70
// Ghidra name: FUN_140216e70
// ============ 0x140216e70 FUN_140216e70 (size=404) ============


undefined8 FUN_140216e70(longlong param_1)



{

  char cVar1;

  int iVar2;

  undefined4 uVar3;

  undefined4 uVar4;

  undefined8 *puVar5;

  longlong *plVar6;

  int iVar7;

  undefined8 uVar8;

  longlong lVar9;

  undefined8 uVar10;

  undefined *puVar11;

  char *pcVar12;

  double dVar13;

  

  cVar1 = *(char *)(param_1 + 0x94);

  uVar8 = FUN_1402170f0(cVar1);

  lVar9 = FUN_1401841a0(1,0x18);

  *(longlong *)(param_1 + 200) = lVar9;

  if (lVar9 != 0) {

    iVar7 = *(int *)(param_1 + 0x84) * 1000;

    iVar2 = *(int *)(param_1 + 0x68);

    *(int *)(lVar9 + 8) = iVar7 / iVar2;

    lVar9 = FUN_140142960("SDL_AUDIO_DISK_TIMESCALE",(longlong)iVar7 % (longlong)iVar2 & 0xffffffff)

    ;

    if ((lVar9 != 0) && (dVar13 = (double)thunk_FUN_1402de5ec(lVar9), 0.0 <= dVar13)) {

      dVar13 = (double)thunk_FUN_1402e1d50((double)*(uint *)(*(longlong *)(param_1 + 200) + 8) *

                                           dVar13);

      *(int *)(*(longlong *)(param_1 + 200) + 8) = (int)(longlong)dVar13;

    }

    puVar5 = *(undefined8 **)(param_1 + 200);

    puVar11 = &DAT_14030a390;

    if (cVar1 != '\0') {

      puVar11 = &DAT_14039be7c;

    }

    uVar10 = FUN_14012c130(uVar8,puVar11);

    *puVar5 = uVar10;

    plVar6 = *(longlong **)(param_1 + 200);

    if (*plVar6 != 0) {

      if (cVar1 == '\0') {

        lVar9 = FUN_1401841f0((longlong)*(int *)(param_1 + 0x6c));

        plVar6[2] = lVar9;

        lVar9 = *(longlong *)(*(longlong *)(param_1 + 200) + 0x10);

        if (lVar9 == 0) {

          return 0;

        }

        FUN_1402f94c0(lVar9,*(undefined4 *)(param_1 + 0x88),(longlong)*(int *)(param_1 + 0x6c));

      }

      FUN_14012e050(4,"You are using the SDL disk i/o audio driver!");

      uVar3 = *(undefined4 *)(param_1 + 0x68);

      uVar4 = *(undefined4 *)(param_1 + 100);

      uVar10 = FUN_140216d80(*(undefined4 *)(param_1 + 0x60));

      pcVar12 = "Writing to";

      if (cVar1 != '\0') {

        pcVar12 = "Reading from";

      }

      FUN_14012e050(4," %s file [%s], format=%s channels=%d freq=%d.",pcVar12,uVar8,uVar10,uVar4,

                    uVar3);

      return 1;

    }

  }

  return 0;

}




