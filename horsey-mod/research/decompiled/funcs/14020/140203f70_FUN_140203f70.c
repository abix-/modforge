// Address: 0x140203f70
// Ghidra name: FUN_140203f70
// ============ 0x140203f70 FUN_140203f70 (size=460) ============


undefined8

FUN_140203f70(undefined8 param_1,longlong param_2,longlong param_3,longlong param_4,int param_5,

             longlong param_6,int param_7,longlong param_8,int param_9,int param_10,

             longlong param_11,int param_12,int param_13,float param_14,float param_15)



{

  undefined4 *puVar1;

  int iVar2;

  char cVar3;

  float *pfVar4;

  longlong lVar5;

  float *pfVar6;

  uint uVar7;

  longlong lVar8;

  uint uVar9;

  undefined4 local_68;

  undefined4 uStack_64;

  undefined4 uStack_60;

  undefined4 uStack_5c;

  

  cVar3 = FUN_1401538c0();

  if (param_11 != 0) {

    param_10 = param_12;

  }

  lVar8 = (longlong)param_10;

  lVar5 = 0x18;

  if (param_3 != 0) {

    lVar5 = 0x20;

  }

  pfVar4 = (float *)FUN_14014b940(param_1,lVar5 * lVar8,0,param_2 + 8);

  if (pfVar4 != (float *)0x0) {

    uVar9 = 0;

    *(longlong *)(param_2 + 0x10) = lVar8;

    iVar2 = 0;

    if (param_11 != 0) {

      iVar2 = param_13;

    }

    if (0 < lVar8) {

      lVar5 = 0;

      do {

        if (iVar2 == 4) {

          uVar7 = *(uint *)(param_11 + lVar5 * 4);

        }

        else if (iVar2 == 2) {

          uVar7 = (uint)*(ushort *)(param_11 + lVar5 * 2);

        }

        else {

          uVar7 = uVar9;

          if (iVar2 == 1) {

            uVar7 = (uint)*(byte *)(lVar5 + param_11);

          }

        }

        *pfVar4 = param_14 * *(float *)((int)(uVar7 * param_5) + param_4);

        pfVar4[1] = param_15 * *(float *)((longlong)(int)(uVar7 * param_5) + 4 + param_4);

        puVar1 = (undefined4 *)((int)(uVar7 * param_7) + param_6);

        local_68 = *puVar1;

        uStack_64 = puVar1[1];

        uStack_60 = puVar1[2];

        uStack_5c = puVar1[3];

        if (cVar3 != '\0') {

          FUN_14014bd40(&local_68);

        }

        *(ulonglong *)(pfVar4 + 2) = CONCAT44(uStack_64,local_68);

        *(ulonglong *)(pfVar4 + 4) = CONCAT44(uStack_5c,uStack_60);

        pfVar6 = pfVar4 + 6;

        if (param_3 != 0) {

          *pfVar6 = *(float *)((int)(uVar7 * param_9) + param_8);

          pfVar4[7] = *(float *)((longlong)(int)(uVar7 * param_9) + 4 + param_8);

          pfVar6 = pfVar4 + 8;

        }

        uVar9 = uVar9 + 1;

        lVar5 = lVar5 + 1;

        pfVar4 = pfVar6;

      } while (lVar5 < lVar8);

    }

    return 1;

  }

  return 0;

}




