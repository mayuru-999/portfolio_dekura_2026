using UnityEngine;

namespace Player
{
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

