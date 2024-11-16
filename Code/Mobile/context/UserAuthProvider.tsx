import { createContext, useContext, useEffect, useState, ReactNode } from "react";
import { getCurrentUser } from "../lib/appwrite";

type UserAuthContextType = {
    isLoggedIn: boolean;
    setIsLoggedIn: (isLoggedIn: boolean) => void;
    user: any | null;
    setUser: (user: any | null) => void;
    loading: boolean;
    setLoading: (loading: boolean) => void;
}

const UserAuthContextDefaultValues: UserAuthContextType = {
    isLoggedIn: false,
    setIsLoggedIn: () => { throw new Error("setIsLoggedIn function is not initialized."); },
    user: null,
    setUser: () => { throw new Error("setUser function is not initialized."); },
    loading: true,
    setLoading: () => { throw new Error("setLoading function is not initialized."); }
}

const UserAuthContext = createContext<UserAuthContextType>(UserAuthContextDefaultValues);

export const UserAuthProvider = ({ children }: { children: ReactNode }) => {
    const [isLoggedIn, setIsLoggedIn] = useState<boolean>(false);
    const [user, setUser] = useState<any | null>(null);
    const [loading, setLoading] = useState<boolean>(true);

    useEffect(() => {
        getCurrentUser()
            .then((res) => {
                if (res) {
                    setIsLoggedIn(true);
                    setUser(res);
                }
            })
            .catch((error) => {
                console.error("Error fetching current user:", error);
            })
            .finally(() => {
                setLoading(false);
            });
    }, []);

    return (
        <UserAuthContext.Provider value={{ isLoggedIn, setIsLoggedIn, user, setUser, loading, setLoading }}>
            {children}
        </UserAuthContext.Provider>
    );
}

export const useUserAuth = () => {
    const context = useContext(UserAuthContext);
    if (!context) {
        throw new Error("useUserAuth must be used within a UserAuthProvider");
    }
    return context;
}