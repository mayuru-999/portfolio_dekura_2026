using UnityEngine;
using UnityEngine.InputSystem;

namespace debug_main
{
#if UNITY_EDITOR
    public class debug_BallSpawner : MonoBehaviour
    {
        public GameObject ballPrefab;
        public Key key = Key.Space;

        private void Update()
        {
            if (Keyboard.current != null && Keyboard.current.spaceKey.wasPressedThisFrame)
            {
                Instantiate(ballPrefab, transform.position, transform.rotation);
            }
        }
    }
#endif
}
