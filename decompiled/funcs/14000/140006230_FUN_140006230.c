// Address: 0x140006230
// Ghidra name: FUN_140006230
// ============ 0x140006230 FUN_140006230 (size=446) ============


void FUN_140006230(longlong param_1,longlong param_2)



{

  longlong *plVar1;

  char cVar2;

  longlong lVar3;

  longlong lVar4;

  

  if ((*(byte *)(param_1 + 0x19298) & 2) != 0) {

    FID_conflict__assert

              (L"IsLocked() == false",L"C:\\dev\\Box2d2\\Box2D\\Dynamics\\b2World.cpp",0x112);

  }

  if ((*(byte *)(param_1 + 0x19298) & 2) == 0) {

    cVar2 = *(char *)(param_2 + 0x71);

    if (*(longlong *)(param_2 + 0x10) != 0) {

      *(undefined8 *)(*(longlong *)(param_2 + 0x10) + 0x18) = *(undefined8 *)(param_2 + 0x18);

    }

    if (*(longlong *)(param_2 + 0x18) != 0) {

      *(undefined8 *)(*(longlong *)(param_2 + 0x18) + 0x10) = *(undefined8 *)(param_2 + 0x10);

    }

    if (param_2 == *(longlong *)(param_1 + 0x19328)) {

      *(undefined8 *)(param_1 + 0x19328) = *(undefined8 *)(param_2 + 0x18);

    }

    lVar3 = *(longlong *)(param_2 + 0x60);

    lVar4 = *(longlong *)(param_2 + 0x68);

    if ((*(ushort *)(lVar3 + 4) & 2) == 0) {

      *(undefined4 *)(lVar3 + 0xac) = 0;

      *(ushort *)(lVar3 + 4) = *(ushort *)(lVar3 + 4) | 2;

    }

    if ((*(ushort *)(lVar4 + 4) & 2) == 0) {

      *(undefined4 *)(lVar4 + 0xac) = 0;

      *(ushort *)(lVar4 + 4) = *(ushort *)(lVar4 + 4) | 2;

    }

    plVar1 = (longlong *)(param_2 + 0x38);

    if (*(longlong *)(param_2 + 0x30) != 0) {

      *(longlong *)(*(longlong *)(param_2 + 0x30) + 0x18) = *plVar1;

    }

    if (*plVar1 != 0) {

      *(undefined8 *)(*plVar1 + 0x10) = *(undefined8 *)(param_2 + 0x30);

    }

    if (param_2 + 0x20 == *(longlong *)(lVar3 + 0x80)) {

      *(longlong *)(lVar3 + 0x80) = *plVar1;

    }

    *(undefined8 *)(param_2 + 0x30) = 0;

    *plVar1 = 0;

    plVar1 = (longlong *)(param_2 + 0x58);

    if (*(longlong *)(param_2 + 0x50) != 0) {

      *(longlong *)(*(longlong *)(param_2 + 0x50) + 0x18) = *plVar1;

    }

    if (*plVar1 != 0) {

      *(undefined8 *)(*plVar1 + 0x10) = *(undefined8 *)(param_2 + 0x50);

    }

    if (param_2 + 0x40 == *(longlong *)(lVar4 + 0x80)) {

      *(longlong *)(lVar4 + 0x80) = *plVar1;

    }

    *(undefined8 *)(param_2 + 0x50) = 0;

    *plVar1 = 0;

    FUN_140010b00(param_2,param_1);

    if (*(int *)(param_1 + 0x19334) < 1) {

      FID_conflict__assert

                (L"m_jointCount > 0",L"C:\\dev\\Box2d2\\Box2D\\Dynamics\\b2World.cpp",0x15a);

    }

    *(int *)(param_1 + 0x19334) = *(int *)(param_1 + 0x19334) + -1;

    if (cVar2 == '\0') {

      for (plVar1 = *(longlong **)(lVar4 + 0x88); plVar1 != (longlong *)0x0;

          plVar1 = (longlong *)plVar1[3]) {

        if (*plVar1 == lVar3) {

          *(uint *)(plVar1[1] + 8) = *(uint *)(plVar1[1] + 8) | 8;

        }

      }

    }

  }

  return;

}




