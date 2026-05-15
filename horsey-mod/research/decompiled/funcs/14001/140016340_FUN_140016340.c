// Address: 0x140016340
// Ghidra name: FUN_140016340
// ============ 0x140016340 FUN_140016340 (size=356) ============


void FUN_140016340(undefined8 *param_1,longlong param_2,int param_3)



{

  undefined4 uVar1;

  int iVar2;

  undefined4 *puVar3;

  

  iVar2 = *(int *)(param_2 + 8);

  if (iVar2 == 0) {

    *(undefined4 *)(param_1 + 3) = 1;

  }

  else {

    if (iVar2 != 1) {

      if (iVar2 != 2) {

        if (iVar2 != 3) {

          FID_conflict__assert(L"false",L"C:\\dev\\Box2d2\\Box2D\\Collision\\b2Distance.cpp",0x51);

          return;

        }

        if ((param_3 < 0) || (*(int *)(param_2 + 0x18) <= param_3)) {

          FID_conflict__assert

                    (L"0 <= index && index < chain->GetVertexCount()",

                     L"C:\\dev\\Box2d2\\Box2D\\Collision\\b2Distance.cpp",0x35);

        }

        if ((param_3 < 0) || (*(int *)(param_2 + 0x18) <= param_3)) {

          FID_conflict__assert

                    (L"0 <= index && index < m_count",

                     L"C:\\dev\\Box2d2\\Box2D\\Collision\\Shapes\\b2ChainShape.h",0x58);

        }

        *param_1 = *(undefined8 *)(*(longlong *)(param_2 + 0x10) + (longlong)param_3 * 8);

        if (param_3 + 1 < *(int *)(param_2 + 0x18)) {

          puVar3 = (undefined4 *)FUN_1400162f0(param_2);

        }

        else {

          if (*(int *)(param_2 + 0x18) < 1) {

            FID_conflict__assert

                      (L"0 <= index && index < m_count",

                       L"C:\\dev\\Box2d2\\Box2D\\Collision\\Shapes\\b2ChainShape.h",0x58);

          }

          puVar3 = *(undefined4 **)(param_2 + 0x10);

        }

        uVar1 = puVar3[1];

        *(undefined4 *)(param_1 + 1) = *puVar3;

        *(undefined4 *)((longlong)param_1 + 0xc) = uVar1;

        param_1[2] = param_1;

        *(undefined4 *)(param_1 + 3) = 2;

        *(undefined4 *)((longlong)param_1 + 0x1c) = *(undefined4 *)(param_2 + 0xc);

        return;

      }

      param_1[2] = param_2 + 0x18;

      *(undefined4 *)(param_1 + 3) = *(undefined4 *)(param_2 + 0x98);

      goto LAB_14001648e;

    }

    *(undefined4 *)(param_1 + 3) = 2;

  }

  param_1[2] = param_2 + 0x10;

LAB_14001648e:

  *(undefined4 *)((longlong)param_1 + 0x1c) = *(undefined4 *)(param_2 + 0xc);

  return;

}




