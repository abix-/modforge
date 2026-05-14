// Address: 0x14015c0a0
// Ghidra name: FUN_14015c0a0
// ============ 0x14015c0a0 FUN_14015c0a0 (size=374) ============


undefined8 FUN_14015c0a0(undefined4 *param_1,undefined1 *param_2)



{

  char cVar1;

  int iVar2;

  char *_Str1;

  undefined8 uVar3;

  undefined4 *puVar4;

  longlong lVar5;

  undefined2 local_res8 [4];

  undefined2 local_res10 [4];

  undefined4 local_68;

  undefined4 uStack_64;

  undefined4 uStack_60;

  undefined4 uStack_5c;

  undefined8 local_58;

  undefined8 uStack_50;

  undefined8 local_48;

  undefined8 uStack_40;

  undefined8 local_38;

  undefined8 uStack_30;

  undefined8 local_28;

  undefined8 uStack_20;

  undefined8 local_18;

  

  *param_2 = 0;

  cVar1 = FUN_14013f5e0(*param_1);

  if ((cVar1 == '\0') || (0 < (int)param_1[0x24])) {

LAB_14015c1ff:

    uVar3 = 0;

  }

  else {

    _Str1 = (char *)FUN_140142960("SDL_GAMECONTROLLER_SENSOR_FUSION");

    if ((_Str1 == (char *)0x0) || (*_Str1 == '\0')) {

LAB_14015c1bd:

      if ((*(longlong *)(param_1 + 2) == 0) ||

         ((lVar5 = thunk_FUN_1402c9340(*(longlong *)(param_1 + 2),"Backbone One"), lVar5 == 0 &&

          (lVar5 = thunk_FUN_1402c9340(*(undefined8 *)(param_1 + 2),"Kishi"), lVar5 == 0)))) {

        cVar1 = FUN_140157410(param_1);

        if (cVar1 == '\0') goto LAB_14015c1ff;

        *param_2 = 1;

      }

    }

    else {

      if ((*_Str1 != '@') && (iVar2 = strncmp(_Str1,"0x",2), iVar2 != 0)) {

        uVar3 = FUN_1401429e0(_Str1,0);

        return uVar3;

      }

      local_58 = 0;

      uStack_50 = 0;

      local_18 = 0;

      local_48 = 0;

      uStack_40 = 0;

      local_38 = 0;

      uStack_30 = 0;

      local_28 = 0;

      uStack_20 = 0;

      puVar4 = (undefined4 *)FUN_1401585d0(&local_68,param_1);

      local_68 = *puVar4;

      uStack_64 = puVar4[1];

      uStack_60 = puVar4[2];

      uStack_5c = puVar4[3];

      FUN_1401582b0(&local_68,local_res10,local_res8,0,0);

      FUN_140159c80(&local_58,_Str1,0);

      cVar1 = FUN_14015bf20(local_res10[0],local_res8[0],&local_58);

      FUN_140157990(&local_58);

      if (cVar1 == '\0') goto LAB_14015c1bd;

    }

    uVar3 = 1;

  }

  return uVar3;

}




