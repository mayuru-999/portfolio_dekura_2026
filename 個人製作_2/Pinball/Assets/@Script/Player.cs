using System;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.InputSystem;

namespace Player
{
    public class Player_Action : MonoBehaviour
    {
        [Header("操作オプション")]
        [SerializeField] Key flipper_L = Key.Z;
        [SerializeField] Key flipper_R = Key.X;
        [SerializeField] Key shake = Key.R;

#if UNITY_EDITOR
        [Header("操作オプション(DEBUG)")]
        [SerializeField] Key spone = Key.Space;
#endif

        private Dictionary<Key, Action> keyAction = new Dictionary<Key, Action>();

        private void Awake()
        {
            keyAction[flipper_L] = () => Flipper.UpdateSpring(flipper_L);
            keyAction[flipper_R] = () => Flipper.UpdateSpring(flipper_R);
            keyAction[shake] = () => Shake.Shaking();
        }

        private void FixedUpdate()
        {
            foreach(var k in keyAction.Keys)
            {
                if (Keyboard.current != null && Keyboard.current[k].isPressed) 
                {
                    keyAction[k].Invoke();
                }
            }
        }
    }

    public class Player_Points : MonoBehaviour
    {
        [SerializeField] private int nowPoint = 0;

        //------------------------------------------//
        public int NowPoint { get { return nowPoint; } }
    }

    public static class AddPointer
    {
        public static void AddPoint(int value, Vector3 hitPosition)
        {
            if (PopupManager.Instance != null)
            {
                PopupManager.Instance.ShowDamage(hitPosition, value, false);
            }
        }
    }
}

