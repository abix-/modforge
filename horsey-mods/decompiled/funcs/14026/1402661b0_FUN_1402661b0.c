// Address: 0x1402661b0
// Ghidra name: FUN_1402661b0
// ============ 0x1402661b0 FUN_1402661b0 (size=372) ============


undefined1 FUN_1402661b0(undefined8 *param_1,undefined8 param_2,longlong param_3,int param_4)



{

  undefined8 uVar1;

  longlong lVar2;

  byte bVar3;

  

  uVar1 = FUN_140149300();

  if ((0 < *(int *)(*(longlong *)*param_1 + 0x8c)) &&

     (lVar2 = FUN_1401581c0(*(undefined4 *)((longlong)param_1 + 0xc)), lVar2 != 0)) {

    if (param_4 < 0x11) {

      FUN_14012e080(7,"GIP: Discarding too-short raw report");

      return 0;

    }

    if (((*(byte *)((longlong)param_1 + 0x14c) & 4) != 0) && (*(int *)(param_1 + 0x29) == 2)) {

      if ((*(byte *)(param_3 + 0xf) & 3) == 0) {

        FUN_14015ad00(uVar1,lVar2,*(undefined1 *)((longlong)param_1 + 0x155),

                      *(byte *)(param_3 + 0xe) & 1);

        FUN_14015ad00(uVar1,lVar2,*(char *)((longlong)param_1 + 0x155) + '\x01',

                      *(byte *)(param_3 + 0xe) >> 1 & 1);

        FUN_14015ad00(uVar1,lVar2,*(char *)((longlong)param_1 + 0x155) + '\x02',

                      *(byte *)(param_3 + 0xe) >> 2 & 1);

        bVar3 = *(byte *)(param_3 + 0xe) >> 3 & 1;

      }

      else {

        FUN_14015ad00(uVar1,lVar2,*(undefined1 *)((longlong)param_1 + 0x155),0);

        FUN_14015ad00(uVar1,lVar2,*(char *)((longlong)param_1 + 0x155) + '\x01',0);

        FUN_14015ad00(uVar1,lVar2,*(char *)((longlong)param_1 + 0x155) + '\x02',0);

        bVar3 = 0;

      }

      FUN_14015ad00(uVar1,lVar2,*(char *)((longlong)param_1 + 0x155) + '\x03',bVar3);

    }

  }

  return 1;

}




