// Address: 0x14027caf0
// Ghidra name: FUN_14027caf0
// ============ 0x14027caf0 FUN_14027caf0 (size=249) ============


void FUN_14027caf0(undefined8 param_1,longlong param_2,void *param_3,int param_4)



{

  char cVar1;

  int iVar2;

  undefined8 uVar3;

  

  uVar3 = FUN_140149300();

  if (param_4 == 0x11) {

    if (*(char *)((longlong)param_3 + 0xf) != '\0') {

      iVar2 = memcmp(param_3,(void *)(param_2 + 0x5c),0xe);

      if (iVar2 != 0) {

        *(undefined1 *)((longlong)param_3 + 0xe) = 0;

      }

    }

    if (*(byte *)(param_2 + 0x30) != *(byte *)((longlong)param_3 + 0xe)) {

      cVar1 = *(char *)(param_2 + 0x2d);

      FUN_14015ad00(uVar3,param_1,cVar1 + '\v',*(byte *)((longlong)param_3 + 0xe) & 1);

      FUN_14015ad00(uVar3,param_1,cVar1 + '\f',*(byte *)((longlong)param_3 + 0xe) >> 1 & 1);

      FUN_14015ad00(uVar3,param_1,cVar1 + 0xdU,*(byte *)((longlong)param_3 + 0xe) >> 2 & 1);

      FUN_14015ad00(uVar3,param_1,(byte)(cVar1 + 0xdU) + 1,

                    *(byte *)((longlong)param_3 + 0xe) >> 3 & 1);

      *(undefined1 *)(param_2 + 0x30) = *(undefined1 *)((longlong)param_3 + 0xe);

    }

    *(undefined1 *)(param_2 + 0x2b) = 1;

  }

  return;

}




