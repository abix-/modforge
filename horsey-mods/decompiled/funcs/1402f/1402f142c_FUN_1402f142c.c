// Address: 0x1402f142c
// Ghidra name: FUN_1402f142c
// ============ 0x1402f142c FUN_1402f142c (size=231) ============


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



undefined8 FUN_1402f142c(undefined8 *param_1)



{

  ulonglong uVar1;

  longlong lVar2;

  longlong *plVar3;

  undefined4 uVar4;

  

  uVar1 = *(ulonglong *)*param_1;

  FUN_1402e1948(*(undefined8 *)param_1[1],param_1[2]);

  __acrt_stdio_free_buffer_nolock(*(undefined8 *)param_1[1]);

  LOCK();

  *(uint *)(*(longlong *)param_1[1] + 0x14) = *(uint *)(*(longlong *)param_1[1] + 0x14) & 0xfffff81f

  ;

  UNLOCK();

  if ((*(byte *)param_1[3] & 4) == 0) {

    lVar2 = *(longlong *)param_1[4];

    uVar4 = (undefined4)(uVar1 & 0xfffffffffffffffe);

    if (lVar2 == 0) {

      lVar2 = _calloc_base(uVar1 & 0xfffffffffffffffe,1);

      FUN_1402e9a80(0);

      if (lVar2 == 0) {

        _DAT_1403fed38 = _DAT_1403fed38 + 1;

        return 0xffffffff;

      }

      plVar3 = *(longlong **)param_1[1];

      LOCK();

      *(uint *)((longlong)plVar3 + 0x14) = *(uint *)((longlong)plVar3 + 0x14) | 0x140;

      UNLOCK();

      *(undefined4 *)(plVar3 + 4) = uVar4;

      *plVar3 = lVar2;

      plVar3[1] = lVar2;

      goto LAB_1402f14fd;

    }

    plVar3 = *(longlong **)param_1[1];

    LOCK();

    *(uint *)((longlong)plVar3 + 0x14) = *(uint *)((longlong)plVar3 + 0x14) | 0x180;

    UNLOCK();

    *(undefined4 *)(plVar3 + 4) = uVar4;

  }

  else {

    plVar3 = *(longlong **)param_1[1];

    lVar2 = (longlong)plVar3 + 0x1c;

    LOCK();

    *(uint *)((longlong)plVar3 + 0x14) = *(uint *)((longlong)plVar3 + 0x14) | 0x400;

    UNLOCK();

    *(undefined4 *)(plVar3 + 4) = 2;

  }

  *plVar3 = lVar2;

  plVar3[1] = lVar2;

LAB_1402f14fd:

  *(undefined4 *)(plVar3 + 2) = 0;

  return 0;

}




