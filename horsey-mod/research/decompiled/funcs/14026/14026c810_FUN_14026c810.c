// Address: 0x14026c810
// Ghidra name: FUN_14026c810
// ============ 0x14026c810 FUN_14026c810 (size=223) ============


int FUN_14026c810(longlong param_1)



{

  char cVar1;

  undefined4 uVar2;

  int iVar3;

  longlong *plVar4;

  undefined1 uVar5;

  int iVar6;

  longlong local_res10;

  

  iVar6 = 0;

  plVar4 = (longlong *)FUN_1401841a0(1,0x170);

  if (plVar4 == (longlong *)0x0) {

    return 0;

  }

  *plVar4 = param_1;

  *(undefined1 *)(plVar4 + 3) = 1;

  uVar2 = FUN_140269a80(param_1);

  *(undefined4 *)((longlong)plVar4 + 0x1c) = uVar2;

  iVar3 = iVar6;

  do {

    iVar6 = iVar6 + 1;

    if (*(char *)(param_1 + 0x54) == '\0') {

      cVar1 = FUN_14026d490(plVar4,1,0,0,1);

      if (cVar1 != '\0') {

        uVar5 = *(undefined1 *)((longlong)plVar4 + 0x43);

        goto LAB_14026c8b0;

      }

    }

    else {

      local_res10 = 0;

      cVar1 = FUN_14026d5b0(plVar4,2,0,0,&local_res10);

      if (cVar1 != '\0') {

        uVar5 = *(undefined1 *)(local_res10 + 0x10);

LAB_14026c8b0:

        iVar3 = FUN_140269280(plVar4,uVar5);

        if (iVar3 != 0) {

LAB_14026c8d2:

          FUN_1401841e0(plVar4);

          return iVar3;

        }

      }

    }

    if (0 < iVar6) goto LAB_14026c8d2;

    FUN_1401492f0(100);

  } while( true );

}




