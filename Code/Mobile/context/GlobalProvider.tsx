import { UserAuthProvider } from "./UserAuthProvider";


export default function GlobalProvider({ children }: { children: React.ReactNode }) {
    return (
        <UserAuthProvider>
            {children}
        </UserAuthProvider>
    )
}