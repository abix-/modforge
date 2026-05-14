// Address: 0x1402681b0
// Ghidra name: FUN_1402681b0
// ============ 0x1402681b0 FUN_1402681b0 (size=333) ============


undefined8 FUN_1402681b0(undefined8 *param_1)



{

  longlong lVar1;

  undefined1 uVar2;

  char cVar3;

  ulonglong uVar4;

  undefined8 uVar5;

  undefined1 local_18;

  ulonglong local_17;

  

  if ((*(byte *)((longlong)param_1 + 0x14c) & 0x20) == 0) {

    return 1;

  }

  if (*(int *)((longlong)param_1 + 0xe4) == 1) {

    if (param_1[0x1d] == 0) goto LAB_14026821a;

    *(undefined4 *)((longlong)param_1 + 0xe4) = 2;

  }

  else if (*(int *)((longlong)param_1 + 0xe4) != 2) goto LAB_14026821a;

  lVar1 = param_1[0x1d];

  uVar4 = FUN_140149350();

  if (lVar1 + 10U <= uVar4) {

    param_1[0x1d] = 0;

    *(undefined4 *)((longlong)param_1 + 0xe4) = 0;

  }

LAB_14026821a:

  if ((*(char *)(param_1 + 0x1e) != '\0') && (*(int *)((longlong)param_1 + 0xe4) == 0)) {

    uVar4 = (ulonglong)*(byte *)(param_1 + 1);

    uVar5 = *param_1;

    local_17 = (ulonglong)

               CONCAT25(0xcd,CONCAT14(*(undefined1 *)((longlong)param_1 + 0xf4),

                                      CONCAT13(*(undefined1 *)((longlong)param_1 + 0xf3),

                                               CONCAT12(*(undefined1 *)((longlong)param_1 + 0xf2),

                                                        CONCAT11(*(undefined1 *)

                                                                  ((longlong)param_1 + 0xf1),0xf))))

                       );

    *(undefined1 *)(param_1 + 0x1e) = 0;

    local_18 = 0;

    uVar2 = FUN_140267f50(param_1,9,0);

    cVar3 = FUN_140267d00(uVar5,9,uVar4 & 0xff,uVar2,&local_18,9,1,FUN_140268190,param_1);

    if (cVar3 == '\0') {

      uVar5 = FUN_14012e850("Couldn\'t send rumble packet");

      return uVar5;

    }

    *(undefined4 *)((longlong)param_1 + 0xe4) = 1;

  }

  return 1;

}




