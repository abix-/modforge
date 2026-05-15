// Address: 0x1400ffb10
// Ghidra name: FUN_1400ffb10
// ============ 0x1400ffb10 FUN_1400ffb10 (size=484) ============


void FUN_1400ffb10(longlong param_1)



{

  longlong lVar1;

  int iVar2;

  int iVar3;

  int iVar4;

  int iVar5;

  int iVar6;

  int iVar7;

  char local_38 [4];

  char local_34 [2];

  char local_32;

  undefined1 local_31;

  undefined8 local_30;

  undefined8 local_28;

  undefined8 local_20;

  

  if ((*(int *)(*(longlong *)((longlong)ThreadLocalStoragePointer + (ulonglong)_tls_index * 8) + 4)

       < DAT_1403fb144) && (FUN_1402c7138(&DAT_1403fb144), DAT_1403fb144 == -1)) {

    local_30 = 0;

    local_28 = 7;

    local_20 = 0xf;

    local_38[0] = s_terrain_140313660[0];

    local_38[1] = s_terrain_140313660[1];

    local_38[2] = s_terrain_140313660[2];

    local_38[3] = s_terrain_140313660[3];

    local_34[0] = s_terrain_140313660[4];

    local_34[1] = s_terrain_140313660[5];

    local_32 = s_terrain_140313660[6];

    local_31 = 0;

    iVar2 = FUN_14006fe60(local_38);

    DAT_1403fb140 = iVar2 + 1;

    _Init_thread_footer(&DAT_1403fb144);

  }

  iVar2 = DAT_1403fb140;

  iVar5 = 0;

  if (0 < *(int *)(param_1 + 0x27c)) {

    do {

      iVar7 = *(int *)(param_1 + 0x278);

      iVar6 = 0;

      if (0 < iVar7) {

        do {

          iVar7 = iVar7 * iVar5 + iVar6;

          lVar1 = (longlong)iVar7 * 0x28;

          if (*(int *)(lVar1 + *(longlong *)(param_1 + 0x270)) == 0x13) {

            *(undefined4 *)(lVar1 + *(longlong *)(param_1 + 0x270)) = 0;

            *(int *)(lVar1 + 8 + *(longlong *)(param_1 + 0x270)) = iVar2 + 1;

            iVar3 = *(int *)(param_1 + 0x278);

            if ((iVar6 < iVar3 + -1) && (iVar5 < *(int *)(param_1 + 0x27c) + -1)) {

              iVar4 = iVar7;

              if (*(int *)(*(longlong *)(param_1 + 0x270) + 0x28 + (longlong)iVar7 * 0x28) == 0x13)

              {

                *(undefined1 *)(*(longlong *)(param_1 + 0x270) + 0xc + lVar1) = 1;

                iVar3 = *(int *)(param_1 + 0x278);

                iVar4 = iVar7 - iVar3;

              }

              if (*(int *)(*(longlong *)(param_1 + 0x270) + (longlong)(iVar3 + iVar7) * 0x28) ==

                  0x13) {

                *(undefined1 *)(*(longlong *)(param_1 + 0x270) + 0xd + lVar1) = 1;

                iVar4 = iVar4 + -1;

              }

              *(undefined4 *)(*(longlong *)(param_1 + 0x270) + lVar1) =

                   *(undefined4 *)((longlong)iVar4 * 0x28 + *(longlong *)(param_1 + 0x270));

              *(undefined4 *)(*(longlong *)(param_1 + 0x270) + 8 + lVar1) =

                   *(undefined4 *)((longlong)iVar4 * 0x28 + 8 + *(longlong *)(param_1 + 0x270));

            }

          }

          iVar6 = iVar6 + 1;

          iVar7 = *(int *)(param_1 + 0x278);

        } while (iVar6 < iVar7);

      }

      iVar5 = iVar5 + 1;

    } while (iVar5 < *(int *)(param_1 + 0x27c));

  }

  return;

}




