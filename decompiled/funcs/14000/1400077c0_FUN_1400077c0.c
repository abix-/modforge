// Address: 0x1400077c0
// Ghidra name: FUN_1400077c0
// ============ 0x1400077c0 FUN_1400077c0 (size=660) ============


/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

/* WARNING: Removing unreachable block (ram,0x00014000782b) */



void FUN_1400077c0(undefined4 *param_1,longlong *param_2,float *param_3)



{

  longlong lVar1;

  undefined4 *puVar2;

  char cVar3;

  int iVar4;

  longlong lVar5;

  undefined1 auStack_478 [32];

  undefined4 *local_458;

  undefined4 local_450 [256];

  int local_50;

  int local_4c;

  ulonglong local_48;

  

  local_48 = DAT_1403e8b00 ^ (ulonglong)auStack_478;

  local_458 = local_450;

  local_4c = 0x100;

  local_450[0] = *param_1;

  local_50 = 1;

  do {

    puVar2 = local_458;

    local_50 = local_50 + -1;

    iVar4 = local_458[local_50];

    lVar5 = (longlong)iVar4;

    if (iVar4 != -1) {

      lVar1 = *(longlong *)(param_1 + 2);

      if ((((*param_3 - *(float *)(lVar1 + 8 + lVar5 * 0x28) <= 0.0) &&

           (param_3[1] - *(float *)(lVar1 + 0xc + lVar5 * 0x28) <= 0.0)) &&

          (*(float *)(lVar1 + lVar5 * 0x28) - param_3[2] <= 0.0)) &&

         (*(float *)(lVar1 + 4 + lVar5 * 0x28) - param_3[3] <= 0.0)) {

        if (*(int *)(lVar1 + 0x1c + lVar5 * 0x28) == -1) {

          lVar1 = *param_2;

          if ((iVar4 < 0) || (*(int *)(lVar1 + 0x14) <= iVar4)) {

            FID_conflict__assert

                      (L"0 <= proxyId && proxyId < m_nodeCapacity",

                       L"C:\\dev\\Box2d2\\Box2D\\Collision\\b2DynamicTree.h",0x99);

          }

          cVar3 = (**(code **)(*(longlong *)param_2[1] + 8))

                            ((longlong *)param_2[1],

                             *(undefined8 *)

                              (*(longlong *)(*(longlong *)(lVar1 + 8) + 0x10 + lVar5 * 0x28) + 0x10)

                            );

          if (cVar3 == '\0') break;

        }

        else {

          if (local_50 == local_4c) {

            iVar4 = local_4c << 3;

            local_4c = local_4c * 2;

            local_458 = (undefined4 *)_malloc_base((longlong)iVar4);

            FUN_1402f8e20(local_458,puVar2,(longlong)local_50 << 2);

            if (puVar2 != local_450) {

              thunk_FUN_1402e9a80(puVar2);

            }

          }

          puVar2 = local_458;

          local_458[local_50] = *(undefined4 *)(lVar1 + 0x1c + lVar5 * 0x28);

          local_50 = local_50 + 1;

          if (local_50 == local_4c) {

            iVar4 = local_4c << 3;

            local_4c = local_4c * 2;

            local_458 = (undefined4 *)_malloc_base((longlong)iVar4);

            FUN_1402f8e20(local_458,puVar2,(longlong)local_50 << 2);

            if (puVar2 != local_450) {

              thunk_FUN_1402e9a80(puVar2);

            }

          }

          local_458[local_50] = *(undefined4 *)(lVar1 + 0x20 + lVar5 * 0x28);

          local_50 = local_50 + 1;

        }

      }

    }

  } while (0 < local_50);

  if (local_458 != local_450) {

    thunk_FUN_1402e9a80();

  }

  return;

}




